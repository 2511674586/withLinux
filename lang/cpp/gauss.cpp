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

int
main (int argc, char **argv)
{
	FLAGS_logtostderr = 1;
	google::InitGoogleLogging (argv[0]);

    /* this is just a test */
	//int MM=3, NN=3, KK=1;
	//float AA[MM*NN] = { 0,0,1, 0,1,0, 1,0,0 };
    //dump_matrix (CblasRowMajor, AA, MM, NN, "AA");
	//float BB[NN*KK] = { 1,2,3 };
    //dump_matrix (CblasRowMajor, BB, MM, KK, "BB");
	//float CC[MM*KK] = {0,0,0};
    //dump_matrix (CblasRowMajor, CC, MM, KK, "CC");
	//cblas_sgemm (CblasRowMajor, CblasNoTrans, CblasNoTrans, MM, KK, NN,
	//	1.0, AA, MM, BB, KK, 0.0, CC, KK);
    //dump_matrix<float> (CblasRowMajor, CC, MM, KK, "CC");
    //LOG(INFO) << "test complete";


    LOG(INFO) << "Gauss-Seidel, Solving Ax=b, with CBLAS";
    // --[ Configuration
    int step_max = 1e+5;
    float converge_threshold = 1e-8;

    int M = 2, N = 2, K = 1;
    float A[M*N] = { 16,3, 7,-11 };
    float b[M*K] = { 11, 13 };
    float x[N*K] = { 0, 0 };
    float test[N*K] = { 0, 0 };

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

        step_gauss_seidel (CblasRowMajor, A, x, b, M, N, K); // update value for vector x
        //LOG(INFO) << "x = step_gauss_seidel (..., x)";
        //dump_matrix (CblasRowMajor, x, N, K, "x"); // dump x

        /* test */
        cblas_scopy (N, x, 1, test, 1); // copy x for testing the error

        //LOG(INFO) << "test = copy(x, test)";
        //dump_matrix (CblasRowMajor,test, N, K, "test"); // cory [OK]

        //LOG(INFO) << "test = sgemm( 1.0, A, x, 0, test)";
        cblas_sgemv (CblasRowMajor, CblasNoTrans, M, N,
            1.0, A, M, x, 1, 0.0, test, 1); // forward current result
        //cblas_sgemm (CblasRowMajor, CblasNoTrans, CblasNoTrans,
        //    M, K, N,  // m k n
        //    1.0, A, M, // alpha, A, lda
        //    test, K,  // B, ldb
        //    1.0, x, K); // beta C  ldc
        //test[0] = A[0]*x[0] + A[1]*x[1];
        //test[1] = A[2]*x[0] + A[3]*x[1];
        //cblas_sgemm (CblasRowMajor, CblasNoTrans, CblasNoTrans, 2, 1, 2,
        //    1.0, A, 2, x, 1, 0.0, test, 1);


        //dump_matrix (CblasRowMajor, A, M, N, "A");
        //dump_matrix (CblasRowMajor, test, N, K, "test");
        //dump_matrix (CblasRowMajor, b, M, K, "b");

        //LOG(INFO) << "test = saxpy(-1, b, 1, test)";
        //test[0] = test[0] - b[0];
        //test[1] = test[1] - b[1];
        cblas_saxpy (N, -1.0, b, 1, test, 1); //  test = test - b
        //dump_matrix (CblasRowMajor, test, N, K, "test");

        asum = cblas_sasum (N, test, 1);
        LOG(INFO) << "  Sasum (test) = " << asum;
        if (asum <= converge_threshold)
            break;
    }
    
    LOG(INFO) << "Converged.";
    LOG(INFO) << "";
    LOG(INFO) << "Solution: ";
    dump_matrix (CblasRowMajor, x, N, K, "x");

    return 0;
}

/*

Reference:

1. https://en.wikipedia.org/wiki/Gauss%E2%80%93Seidel_method


*/
