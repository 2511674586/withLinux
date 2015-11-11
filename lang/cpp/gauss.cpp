// C++ Gauss-Seidel with BLAS
// 2015 Lumin Zhou

#include <iostream>
#include <string>
#include <vector>

#include <glog/logging.h>
#include <cblas.h>

using namespace std;

/* get value of element from matrix */
template <typename Dtype>
Dtype
get_value (const CBLAS_ORDER order, 
    Dtype * matrix, int rows, int columns, int i, int j)
{
    CHECK_LE(i, rows)    << "index i exceeds MAX rows.";
    CHECK_LE(j, columns) << "index j exceeds MAX columns.";
    if (CblasRowMajor == order)
        return (Dtype) matrix[ i*columns + j ]; 
    else
        return (Dtype) matrix[ j*rows + i ]; 
}

/* for internal use of dump_matrix() */
template <typename Dtype>
void
_dump_matrix (const CBLAS_ORDER order, 
    Dtype * matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++) {
		cout << "\t";
		for (int j = 0; j < columns; j++) {
			cout << get_value(order, matrix, rows, columns, i, j)
                << "  ";
		}
		cout << endl;
	}
    return;
}

/* dump a whole matrix on the screen, with pretty format */
template <typename Dtype>
void
dump_matrix (const CBLAS_ORDER order, 
    Dtype * matrix, int rows, int columns, string name = "Matrix")
{
    std::cout << name << " = [" << std::endl;
    _dump_matrix<Dtype> (order, matrix, rows, columns);
	std::cout << "];" << std::endl;
    return;
}

/* iterates the x */
template <typename Dtype>
void
step_gauss_seidel (const CBLAS_ORDER order,
    const Dtype * A, Dtype * x, const Dtype * b, int M, int K, int N)
{
    CHECK_EQ(M, K) << "M should equal to K.";
    CHECK_EQ(1, N) << "N should be exactly 1.";
    Dtype temp = (Dtype) 0.0;
    for (int i = 0; i < M; i++) {
        temp = (Dtype) 0.0;
        for (int j = 0; j < M; j++) {
            if (i == j)
                continue;
            temp += get_value(order, A, M, K, i, j) * x[j];
        }
        x[i] = (b[i] - temp) / get_value(order, A, M, K, i, i);
    }
    return;
}

/////////////////////////// MAIN ////////////////////////////
int
main (int argc, char **argv)
{
	FLAGS_logtostderr = 1;
	google::InitGoogleLogging (argv[0]);

    LOG(INFO) << "Gauss-Seidel, Solving Ax=b, with CBLAS";

    // --[ Configuration
    int step_max = 1e+3;
    float converge_threshold = 1e-8;

    // example 1 : will converge and get the solution
    //int M = 2, N = 2, K = 1;
    //float A[M*N] = { 16,3, 7,-11 };
    //float b[M*K] = { 11, 13 };
    //float x[N*K] = { 0, 0 };
    //float test[N*K] = { 0, 0 };

    // example 2 : will diverge, only expect that 
    // init value is the solution.
    //int M = 2, N = 2, K = 1;
    //float A[M*N] = { 2,3, 5,7 };
    //float b[M*K] = { 11, 13 };
    //float x[N*K] = { -38, 29 };
    //float test[N*K] = { 0, 0 };

    // example 3 : 
    int M = 4, N = 4, K = 1;
    float A[M*N] = { 10,-1,2,0,  -1,11,-1,3,  2,-1,10,-1,  0,3,-1,8 };
    float b[M*K] = { 6,25,-11,15 };
    float x[N*K] = { 0,0,0,0 };
    float test[N*K] = { 0,0,0,0 };


    // --[ Echo A and b, and init value of x
    dump_matrix (CblasRowMajor, A, M, N, "A");
    dump_matrix (CblasRowMajor, b, M, K, "b");

    LOG(INFO) << "Initialize solution";
    dump_matrix (CblasRowMajor, x, N, K, "x");

    // --[ Begin Gauss-Seidel
    int iter = 0;
    float asum = 0.;
    while (iter++ < step_max) {
        /* update */
        LOG(INFO) << "Step " << iter;

        // update value for vector x
        step_gauss_seidel (CblasRowMajor, A, x, b, M, N, K);

        /* test */
        cblas_sgemv (CblasRowMajor, CblasNoTrans, M, N,
            1.0, A, M, x, 1, 0.0, test, 1); // forward current result
        cblas_saxpy (N, -1.0, b, 1, test, 1); //  test = test - b
        asum = cblas_sasum (N, test, 1); // asum = sum(abs(test))

        LOG(INFO) << "  Sasum (test) = " << asum;
        if (asum <= converge_threshold) break;
    }
    if (iter < step_max)
        LOG(INFO) << "Solution Converged.";
    else
        LOG(INFO) << "Max_step Reached.";

    LOG(INFO) << "";
    LOG(INFO) << "Solution Dump: ";
    dump_matrix (CblasRowMajor, x, N, K, "x");

    return 0;
}

/*

Reference for Gauss-Seidel

1. https://en.wikipedia.org/wiki/Gauss%E2%80%93Seidel_method
2. http://mathworld.wolfram.com/Gauss-SeidelMethod.html

*/
