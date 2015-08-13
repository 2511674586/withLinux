// BLAS demo, cpp
#include <iostream>
#include <glog/logging.h>
#include <cblas.h>

int
main (int argc, char **argv) {
	// Log messeages into stderr
	FLAGS_logtostderr = 1;
	google::InitGoogleLogging (argv[0]);

	LOG(INFO) << "Begin BLAS Demo";
	std::cout << "  A = [ 0 0 1 ; 0 1 0 ; 1 0 0 ]" << std::endl
		<< "  B = [ 1;2;3 ]" << std::endl;
	int M=3, K=3, N=1;
	float A[M*K] = { 0,0,1, 0,1,0, 1,0,0 };
	float B[K*N] = { 1,2,3 };
	float C[M*N];

	// Do matrix multiplication
	LOG(INFO) << "Calculating  C := 1.0 A * B + 0.0 C ";
	cblas_sgemm (CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K,
		1.0, A, K, B, N, 0.0, C, N);

	// Dump matrix	
	LOG(INFO) << "Dumping matrix C";
	std::cout << "C = [" << std::endl;
	for (int i = 1; i <= M; i++) {
		std::cout << "\t";
		for (int j = 1; j <= N; j++) {
			std::cout << C[i*j-1] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "];" << std::endl;

	LOG(INFO) << "Demo done.";
	return 0;
}
