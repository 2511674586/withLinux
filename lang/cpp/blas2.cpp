// C++ Gauss-Seidel with BLAS
// 2015 Lumin Zhou

#include <iostream>
#include <string>

#include <glog/logging.h>
#include <cblas.h>

using namespace std;


template <typename Dtype>
void
_dump_matrix (Dtype * matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++) {
		cout << "\t";
		for (int j = 0; j < columns; j++) {
			cout << matrix[i*columns + j] << " ";
		}
		cout << endl;
	}
}
template <typename Dtype>
void
dump_matrix (Dtype * matrix, int rows, int columns, string name = "")
{
    std::cout << name << " [" << std::endl;
    _dump_matrix<Dtype> (matrix, rows, columns);
	std::cout << "];" << std::endl;
}

int
main (int argc, char **argv) {
	// Log messeages into stderr
	FLAGS_logtostderr = 1;
	google::InitGoogleLogging (argv[0]);

	LOG(INFO) << "Begin BLAS Demo";
	int M=3, K=3, N=1;
	float A[M*K] = { 0,0,1, 0,1,0, 1,0,0 };
    dump_matrix (A, M, K, "A =");
	float B[K*N] = { 1,2,3 };
    dump_matrix (B, K, N, "B =");
	float C[M*N];

	// Do matrix multiplication
	LOG(INFO) << "Calculating  C := 1.0 A * B + 0.0 C ";
	cblas_sgemm (CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K,
		1.0, A, K, B, N, 0.0, C, N);

    dump_matrix<float> (C, M, N, "C = ");

	LOG(INFO) << "Demo done.";
	return 0;
}
