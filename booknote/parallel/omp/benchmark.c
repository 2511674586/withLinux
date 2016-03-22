/**
 * @file benchmark.c
 * @brief benchmark the amount of time saved by parallel program
 * @note compile with '--std=c99'
 * @author Lumin <cdluminate@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <sys/time.h> // high precision timer, gettimeofday()
#include <assert.h>

/**
 * @brief vector length used in L-1 benchmarks
 */
#define VLEN 1024*1024*64

/**
 * @brief matrix size used in L-2 benchmarks
 */
#define MLEN 1024*8

/**
 * @brief matrix size used in L-3 benchmarks
 */
#define MMLEN 512

/**
 * @breif dcopy, L-1 BLAS, serial
 */
void
dcopy_serial (const double * src, double * dest, size_t n)
{
	for (long i = 0; i < n; i++)
		dest[i] = src[i];
	return;
}

/**
 * @brief dcopy, L-1 BLAS, parallel
 */
void
dcopy_parallel (const double * src, double * dest, size_t n)
{
#pragma omp parallel for shared(src, dest)
	for (long i = 0; i < n; i++)
		dest[i] = src[i];
	return;
}

/**
 * @brief dasum, L-1 BLAS, serial
 */
double
dasum_serial (const double * a, size_t n)
{
	double ret = 0.;
	for (long i = 0; i < n; i++) {
		ret += (a[i]>0.)?(a[i]):(-a[i]);
		//if (0 == i % 1000000) printf (" iter %ld, n = %lf\n", i, ret); // debug
	}
	return ret;
}

/**
 * @brief dasum, L-1 BLAS, parallel
 */
double
dasum_parallel (const double * a, size_t n)
{
	double ret = 0.;
#pragma omp parallel for reduction (+:ret)
	for (long i = 0; i < n; i++)
		ret += (a[i]>0.)?(a[i]):(-a[i]);
	return ret;
}

/**
 * @brief dscal, L-1 BLAS, serial
 */
void
dscal_serial (double * x, const double a, size_t n)
{
	for (size_t i = 0; i < n; i++)
		x[i] *= a;
}

/**
 * @brief dscal, L-1 BLAS, parallel
 */
void
dscal_parallel (double * x, const double a, size_t n)
{
#pragma omp parallel for shared(x)
	for (size_t i = 0; i < n; i++)
		x[i] *= a;
}

/**
 * @brief ddot, L-1 BLAS, serial
 */
double
ddot_serial (const double * a, const double * b, size_t n)
{
	double ret = 0.;
	for (long i = 0; i < n; i++)
		ret += a[i] * b[i];
	return ret;
}

/**
 * @brief ddot, L-1 BLAS, parallel
 */
double
ddot_parallel (const double * a, const double * b, size_t n)
{
	double ret = 0.;
#pragma omp parallel for reduction (+:ret)
	for (long i = 0; i < n; i++)
		ret += a[i] * b[i];
	return ret;
}

/**
 * @brief daxpby, L-1 BLAS Extension, serial
 */
void
daxpby_serial (const double * x, const double a,
	double * y, const double b, size_t n)
{
	// a x + b y -> y
	for (long i = 0; i < n; i++)
		y[i] += a * x[i] + b * y[i];
}

/**
 * @brief daxpby, L-1 BLAS Extension, parallel
 */
void
daxpby_parallel (const double * x, const double a,
	double * y, const double b, size_t n)
{
	// a x + b y -> y
#pragma omp parallel for shared(x, y)
	for (long i = 0; i < n; i++)
		y[i] += a * x[i] + b * y[i];
}

/**
 * @brief dgemv, L-2 BLAS, serial
 * @f[ a x * b y -> dest @f]
 */
void
dgemv_serial (const double * x, const double a,
	const double * y, const double b, 
	size_t n, double * dest)
{
	// note, x is matrix !
	for (size_t i = 0; i < n; i++) { // for each row of x
		dest[i] = y[i];
		for (size_t j = 0; j < n; j++) { // for each column of y
			dest[i] += a * *(x+(i*n)+j) * b * y[j];
		}
	}
}

/**
 * @brief dgemv, L-2 BLAS, parallel
 * @f[ a x * b y -> dest @f]
 */
void
dgemv_parallel (const double * x, const double a,
	const double * y, const double b,
	size_t n, double * dest)
{
	size_t j = 0;
#pragma omp parallel for shared(x, y, dest) private(j)
	for (size_t i = 0; i < n; i++) { // for each row of x
		dest[i] = y[i];
		for (j = 0; j < n; j++) { // for each column of y
			dest[i] += a * *(x+(i*n)+j) * b * y[j];
		}
	}
}

/**
 * @brief dgemv, L-2 BLAS, parallel version 2
 * @f[ a x * b y -> dest @f]
 */
void
dgemv_parallelv2 (const double * x, const double a,
	const double * y, const double b,
	size_t n, double * dest)
{
	size_t j = 0;
	size_t i = 0;
	dcopy_parallel(y, dest, n);
#pragma omp parallel for collapse(2) shared(x, y, dest) private(i,j)
	for (i = 0; i < n; i++) { // for each row of x
	for (j = 0; j < n; j++) { // for each column of y
			dest[i] += a * *(x+(i*n)+j) * b * y[j];
	}}
}

/**
 * @brief dgemm, L-3 BLAS, serial version
 * @f[ A_{m x n} * B_{n x k} -> C_{m x k} @f]
 */
void
dgemm_serial (const double * A, const double * B,
	size_t m, size_t n, size_t k, double * C)
{
	size_t mm = 0, nn = 0, kk = 0;
	for (mm = 0; mm < m; mm++) {
		for (kk = 0; kk < k; kk++) {
			*(C+mm*k+kk) = 0;
			for (nn = 0; nn < n; nn++) {
				*(C+mm*k+kk) += *(A+mm*n+nn) * *(B+nn*k+kk);
			}
		}
	}
}

/**
 * @brief dgemm, L-3 BLAS, parallel version
 * @f[ A_{m x n} * B_{n x k} -> C_{m x k} @f]
 */
void
dgemm_parallel (const double * A, const double * B,
	size_t m, size_t n, size_t k, double * C)
{
	size_t mm = 0, nn = 0, kk = 0;
#pragma omp parallel for collapse(2) shared(A, B) private(nn)
// Note, dynamic scheduler seems to reduce performance here
	for (mm = 0; mm < m; mm++) {
	for (kk = 0; kk < k; kk++) {
		*(C+mm*k+kk) = 0;
		for (nn = 0; nn < n; nn++) {
			*(C+mm*k+kk) += *(A+mm*n+nn) * *(B+nn*k+kk);
		}
	}}
}

/**
 * @brief dgemm, L-3 BLAS, parallel version 2
 * @f[ A_{m x n} * B_{n x k} -> C_{m x k} @f]
 */
void
dgemm_parallelv2 (const double * A, const double * B,
	size_t m, size_t n, size_t k, double * C)
{
	size_t mm = 0, nn = 0, kk = 0;
#pragma omp parallel for shared(A, B) private(kk,nn)
	for (mm = 0; mm < m; mm++) {
		for (kk = 0; kk < k; kk++) {
			*(C+mm*k+kk) = 0;
			for (nn = 0; nn < n; nn++) {
				*(C+mm*k+kk) += *(A+mm*n+nn) * *(B+nn*k+kk);
			}
		}
	}
}

/**
 * @brief tell user the time difference in second.
 * @param tvs the starting time stamp.
 * @param tve the ending timp stamp.
 * @see sys/time.h, gettimeofday(2)
 */
void
timediff (struct timeval tvs, struct timeval tve, char * msg)
{
	long diff_sec  = tve.tv_sec - tvs.tv_sec;
	long diff_usec = tve.tv_usec - tvs.tv_usec;
	double dtime = diff_sec + diff_usec/1e+6;
	fprintf (stdout, "I: [%s] time cost is %1.6f seconds.\n",
		(msg==NULL)?"":msg, dtime);
}

/**
 * @brief print a spliting line on screen
 */
void
hrulefill (void)
{
	for (int i = 0; i < 80; i++)
		fprintf (stdout, "-");
	fprintf (stdout, "\n");
	return;
}

/**
 * @brief Lumin's benchmark
 */
int
main (int argc, char ** argv, char ** envp)
{
	fprintf (stdout, "Wellcome to Lumin's serial/parallel benchmark, init ... ");
	fflush(stdout);

	struct timeval tvs; // tv_s, for starting point
	struct timeval tve; // tv_e, for ending point

	gettimeofday(&tvs, NULL); // start init time

	// init for L-1
	double * A = (double *)malloc(VLEN*sizeof(double));
	double * C = (double *)malloc(VLEN*sizeof(double));
	assert(A != NULL);
	assert(C != NULL);
	memset ((void* )A, 0x00, VLEN*sizeof(double));
	memset ((void* )C, 0x00, VLEN*sizeof(double));
	for (long i = 0; i < VLEN; i++)
		A[i] = (double)(1);

	// init for L-2
	double * dest = (double *)malloc(MLEN*sizeof(double));
	double * M = (double *)malloc(MLEN*MLEN*sizeof(double));
	assert(dest != NULL);
	assert(M != NULL);
	memset ((void *)M, 0x00, MLEN*MLEN*sizeof(double));
	for (size_t i = 0; i < MLEN*MLEN; i++)
		*(M + i) = 1.;

	// init for L-3
	double * X = (double *)malloc(MMLEN*MMLEN*sizeof(double));
	double * Y = (double *)malloc(MMLEN*MMLEN*sizeof(double));
	double * Z = (double *)malloc(MMLEN*MMLEN*sizeof(double));
	assert(X != NULL);
	assert(Y != NULL);
	assert(Z != NULL);
	memset ((void *)X, 0x00, MMLEN*MMLEN*sizeof(double));
	memset ((void *)Y, 0x00, MMLEN*MMLEN*sizeof(double));
	memset ((void *)Z, 0x00, MMLEN*MMLEN*sizeof(double));
	for (size_t i = 0; i < MMLEN*MMLEN; i++) {
		*(X + i) = 1.;
		*(Y + i) = 1.;
	}

	// init the rest
	struct timeval tvi; // tv_init
	struct timeval tvt; // tv_terminate
	gettimeofday(&tvi, NULL);
	gettimeofday(&tve, NULL); // end init time
	fprintf(stdout, "[OK]\n");
	timediff(tvs, tve, "initialization");

	hrulefill();
	{ // copy test

		// serial
		gettimeofday(&tvs, NULL);
		dcopy_serial (A, C, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dcopy in serial");

		fprintf (stdout, "     A %lf %lf C %lf %lf \n", A[0], A[1], C[0], C[1]); // check result

		// parallel
		gettimeofday(&tvs, NULL);
		dcopy_parallel (A, C, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dcopy in parallel");

		fprintf (stdout, "     A %lf %lf C %lf %lf \n", A[0], A[1], C[0], C[1]); // check result
	}
	hrulefill();
	{ // asum test

		// serial
		double resA;
		gettimeofday(&tvs, NULL);
		resA = dasum_serial (A, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dasum serial");

		fprintf (stdout, "     resA %lf\n", resA);

		// parallel
		double resB;
		gettimeofday(&tvs, NULL);
		resB = dasum_parallel (A, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dasum parallel");

		fprintf (stdout, "     resB %lf\n", resB);
	}
	hrulefill();
	{ // dot test

		// serial
		double resA;
		gettimeofday(&tvs, NULL);
		resA = ddot_serial (A, C, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "ddot in serial");

		fprintf (stdout, "     resA %lf\n", resA);

		// parallel
		double resB;
		gettimeofday(&tvs, NULL);
		resB = ddot_parallel (A, C, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "ddot in parallel");

		fprintf (stdout, "     resB %lf\n", resB);
	}
	hrulefill();
	{ // scal test

		// serial
		gettimeofday(&tvs, NULL);
		dscal_serial (A, 0.5, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dscal in serial");

		fprintf (stdout, "     A %lf %lf\n", A[0], A[1]); // check result

		// parallel
		gettimeofday(&tvs, NULL);
		dscal_parallel (A, 0.5, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dscal in parallel");

		fprintf (stdout, "     A %lf %lf\n", A[0], A[1]); // check result
	}
	hrulefill();
	{ // axpby test

		// serial
		gettimeofday(&tvs, NULL);
		daxpby_serial (A, 0.5, C, 0.5, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "daxpby in serial");

		fprintf (stdout, "     A %lf %lf C %lf %lf \n", A[0], A[1], C[0], C[1]); // check result

		// parallel
		gettimeofday(&tvs, NULL);
		daxpby_parallel (A, 0.5, C, 0.5, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "daxpby in parallel");

		fprintf (stdout, "     A %lf %lf C %lf %lf \n", A[0], A[1], C[0], C[1]); // check result
	}
	hrulefill();
	{ // gemv test
	
		// serial
		gettimeofday(&tvs, NULL);
		dgemv_serial (M, 1., A, 1., MLEN, dest);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemv in serial");

		fprintf (stdout, "     Y %lf %lf DEST %lf %lf \n", A[0], A[1], dest[0], dest[1]); // check result

		// parallel
		gettimeofday(&tvs, NULL);
		dgemv_parallel (M, 1., A, 1., MLEN, dest);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemv in parallel");

		fprintf (stdout, "     Y %lf %lf DEST %lf %lf \n", A[0], A[1], dest[0], dest[1]); // check result

		// parallelv2
		gettimeofday(&tvs, NULL);
		dgemv_parallelv2 (M, 1., A, 1., MLEN, dest);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemv in parallelv2");

		fprintf (stdout, "     Y %lf %lf DEST %lf %lf \n", A[0], A[1], dest[0], dest[1]); // check result

	}
	hrulefill();
	{ // gemm
	
		// serial
		gettimeofday(&tvs, NULL);
		dgemm_serial (X, Y, MMLEN, MMLEN, MMLEN, Z);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemm in serial");

		fprintf (stdout, "     X %lf %lf Y %lf %lf DEST %lf %lf \n",
			*(X), *(X+1), Y[0], Y[1], *(Z), *(Z+1)); // check result

		// parallel
		gettimeofday(&tvs, NULL);
		dgemm_parallel (X, Y, MMLEN, MMLEN, MMLEN, Z);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemm in parallel");

		fprintf (stdout, "     X %lf %lf Y %lf %lf DEST %lf %lf \n",
			*(X), *(X+1), Y[0], Y[1], *(Z), *(Z+1)); // check result

		// parallel v2
		gettimeofday(&tvs, NULL);
		dgemm_parallelv2 (X, Y, MMLEN, MMLEN, MMLEN, Z);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemm in parallelv2");

		fprintf (stdout, "     X %lf %lf Y %lf %lf DEST %lf %lf \n",
			*(X), *(X+1), Y[0], Y[1], *(Z), *(Z+1)); // check result
	}
	hrulefill();

	// how long all the benchmarks take
	gettimeofday(&tvt, NULL);
	timediff(tvi, tvt, "All benchmark");

	free(A);
	free(C);
	free((void *)dest);
	free((void *)M);
	free((void *)X);
	free((void *)Y);
	free((void *)Z);

	return 0;
}
