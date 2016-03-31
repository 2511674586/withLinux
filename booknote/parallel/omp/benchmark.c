/**
 * @file benchmark.c
 * @brief benchmark the amount of time saved by parallel program
 * @note compile with '--std=c99'
 * @author Lumin <cdluminate@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <omp.h>
#include <sys/time.h> // high precision timer, gettimeofday()
#include <assert.h>

/**
 * @brief flag, set 1 to dump all debug information
 */
int debug = 1;

/**
 * @brief vector length used in L-1 benchmarks
 */
#define VLEN 4

/**
 * @brief matrix size used in L-2 benchmarks
 */
#define MVLEN 4

/**
 * @brief matrix size used in L-3 benchmarks
 */
#define MMLEN 4

/**
 * @brief IMLEN image size, KLEN kernel size, FLEN(IM,K) feature map size
 */
#define IMLEN 4
#define KLEN 2
#define FLEN(im,k) ((im-k+1))

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
 * @brief 2-D convolution in serial 
 * (Computer Vision Convolution, not Signal Convolution)
 * @param[in] smap source map
 * @param[in] dmap destination map
 * @param[in] m smap size
 * @param[in] k kernel size
 * @note no padding
 */
void
conv2_serial (const double * smap, const double * kernel,
	size_t ssize, size_t ksize,
	double * dmap)
{
	for (unsigned int i = 0; i < FLEN(ssize,ksize); i++) { // for each row of output map
	for (unsigned int j = 0; j < FLEN(ssize,ksize); j++) { // for each column of output map
		// element wise mult, smap part with kernel
		double sum = 0.;
		for (unsigned int m = 0; m < ksize; m++) {
		for (unsigned int n = 0; n < ksize; n++) {
			sum += kernel[m*ksize +n] * smap[(i+m)*ssize + j+n];
		}}
		// finish (i,j) of output feature map
		dmap[i*FLEN(ssize,ksize)+j] = sum;
	}}
	return;
}

/**
 * @brief 2-D convolution in parallel
 * (Computer Vision Convolution, not Signal Convolution)
 */
void
conv2_parallel (const double * smap, const double * kernel,
	size_t ssize, size_t ksize,
	double * dmap)
{
	double sum = 0.;
#pragma omp parallel for collapse(2) shared(smap,kernel,dmap) private(sum)
	for (unsigned int i = 0; i < FLEN(ssize,ksize); i++) { // for each row of output map
	for (unsigned int j = 0; j < FLEN(ssize,ksize); j++) { // for each column of output map
		// element wise mult, smap part with kernel
		sum = 0.;
		for (unsigned int m = 0; m < ksize; m++) {
		for (unsigned int n = 0; n < ksize; n++) {
			sum += kernel[m*ksize +n] * smap[(i+m)*ssize + j+n];
		}}
		// finish (i,j) of output feature map
		dmap[i*FLEN(ssize,ksize)+j] = sum;
	}}
	return;
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
 * @brief dump a vector to screen
 */
void
dump_vector (double * v, size_t size)
{
	for (size_t i = 0; i < size; i++)
		fprintf (stdout, " %.3lf", v[i]);
	fprintf (stdout, "\n");
	return;
}

/**
 * @brief dump a matrix to screen
 */
void
dump_matrix (double * m, size_t row, size_t col)
{
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++)
			fprintf (stdout, " %.3lf", m[i*col+j]);
		fprintf (stdout, "\n");
	}
	return;
}

/**
 * @brief allocate a vector in double
 * @note values of vector not initialized on allocation.
 */
double *
new_vector (size_t len)
{
	double * ret = (double *)malloc(len*sizeof(double));
	assert(ret != NULL);
	return ret;
}

/**
 * @brief delete a vector in double
 */
void
del_vector (double * v)
{
	free(v);
}

/**
 * @brief fill a double vector with a value
 */
void
fill_vector (double * v, size_t len, double val)
{
	for (size_t i = 0; i < len; i++)
		v[i] = val;
	return;
}

/**
 * @brief allocate a double matrix
 */
double *
new_matrix (size_t row, size_t col)
{
	double * ret = (double *)malloc(row*col*sizeof(double));
	assert(ret != NULL);
	return ret;
}

/**
 * @brief delete a matrix in double
 */
void
del_matrix (double * m)
{
	free(m);
}

/**
 * @brief fill a double matrix with a value
 */
void
fill_matrix (double * m, size_t row, size_t col, double val)
{
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			m[i*col+j] = val;
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

	// init times
	struct timeval tvi; // tv_init
	struct timeval tvt; // tv_terminate
	gettimeofday(&tvi, NULL);
	gettimeofday(&tve, NULL); // end init time
	fprintf(stdout, "[OK]\n");
	timediff(tvs, tve, "initialization");

	hrulefill();
	{ // copy test

		// data
		double * A = new_vector(VLEN);
		double * C = new_vector(VLEN);
		fill_vector(A, VLEN, 1.);
		fill_vector(C, VLEN, 0.);

		// serial
		gettimeofday(&tvs, NULL);
		dcopy_serial (A, C, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dcopy in serial");

		if (debug) dump_vector(A, VLEN);
		if (debug) dump_vector(C, VLEN);

		// parallel
		gettimeofday(&tvs, NULL);
		dcopy_parallel (A, C, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dcopy in parallel");

		if (debug) dump_vector(A, VLEN);
		if (debug) dump_vector(C, VLEN);

		// post-test
		del_vector(A);
		del_vector(C);

	}
	hrulefill();
	{ // asum test

		// data
		double * A = new_vector(VLEN);
		fill_vector(A, VLEN, 1.);

		// serial
		double resA;
		gettimeofday(&tvs, NULL);
		resA = dasum_serial (A, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dasum serial");

		if (debug) dump_vector(A, VLEN);
		if (debug) fprintf (stdout, " dasum(A) = %lf\n", resA);

		// parallel
		double resB;
		gettimeofday(&tvs, NULL);
		resB = dasum_parallel (A, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dasum parallel");

		if (debug) dump_vector(A, VLEN);
		if (debug) fprintf (stdout, " dasum(A) = %lf\n", resB);

		// post-test
		del_vector(A);

	}
	hrulefill();
	{ // dot test

		// data
		double * A = new_vector(VLEN);
		double * C = new_vector(VLEN);
		fill_vector(A, VLEN, 1.);
		fill_vector(C, VLEN, 1.);

		// serial
		double resA;
		gettimeofday(&tvs, NULL);
		resA = ddot_serial (A, C, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "ddot in serial");

		if (debug) dump_vector(A, VLEN);
		if (debug) dump_vector(C, VLEN);
		if (debug) fprintf (stdout, " ddot(A, C) = %lf\n", resA);

		// parallel
		double resB;
		gettimeofday(&tvs, NULL);
		resB = ddot_parallel (A, C, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "ddot in parallel");

		if (debug) dump_vector(A, VLEN);
		if (debug) dump_vector(C, VLEN);
		fprintf (stdout, " ddot(A, C) = %lf\n", resB);

		// post-test
		del_vector(A);
		del_vector(C);

	}
	hrulefill();
	{ // scal test

		// data
		double * A = new_vector(VLEN);
		fill_vector(A, VLEN, 1.);

		// serial
		gettimeofday(&tvs, NULL);
		dscal_serial (A, 0.5, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dscal in serial");

		if (debug) dump_vector(A, VLEN);

		// parallel
		gettimeofday(&tvs, NULL);
		dscal_parallel (A, 0.5, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dscal in parallel");

		if (debug) dump_vector(A, VLEN);

		// post-test
		del_vector(A);

	}
	hrulefill();
	{ // axpby test

		// data
		double * A = new_vector(VLEN);
		double * C = new_vector(VLEN);
		fill_vector(A, VLEN, 1.);
		fill_vector(C, VLEN, 1.);

		// serial
		gettimeofday(&tvs, NULL);
		daxpby_serial (A, 0.5, C, 0.5, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "daxpby in serial");

		if (debug) dump_vector(A, VLEN);
		if (debug) dump_vector(C, VLEN);

		// parallel
		gettimeofday(&tvs, NULL);
		daxpby_parallel (A, 0.5, C, 0.5, VLEN);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "daxpby in parallel");

		if (debug) dump_vector(A, VLEN);
		if (debug) dump_vector(C, VLEN);

		// post-test
		del_vector(A);
		del_vector(C);
	}
	hrulefill();
	{ // gemv test

		// data
		double * M = new_matrix(MVLEN, MVLEN);
		double * A = new_vector(MVLEN);
		double * Y = new_vector(MVLEN);
		fill_matrix(M, MVLEN, MVLEN, 1.);
		fill_vector(A, MVLEN, 1.);
		fill_vector(Y, MVLEN, 1.);
	
		if (debug) dump_matrix(M, MVLEN, MVLEN);
		if (debug) dump_vector(A, MVLEN);

		// serial
		gettimeofday(&tvs, NULL);
		dgemv_serial (M, 1., A, 1., MVLEN, Y);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemv in serial");

		if (debug) dump_vector(Y, MVLEN);

		// parallel
		gettimeofday(&tvs, NULL);
		dgemv_parallel (M, 1., A, 1., MVLEN, Y);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemv in parallel");

		if (debug) dump_vector(Y, MVLEN);

		// parallelv2
		gettimeofday(&tvs, NULL);
		dgemv_parallelv2 (M, 1., A, 1., MVLEN, Y);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemv in parallelv2");

		if (debug) dump_vector(Y, MVLEN);

		// post-test
		del_matrix(M);
		del_vector(A);
		del_vector(Y);

	}
	hrulefill();
	{ // gemm

		// data
		double * X = new_matrix(MMLEN, MMLEN);
		double * Y = new_matrix(MMLEN, MMLEN);
		double * Z = new_matrix(MMLEN, MMLEN);
		fill_matrix(X, MMLEN, MMLEN, 1.);
		fill_matrix(Y, MMLEN, MMLEN, 1.);
		fill_matrix(Z, MMLEN, MMLEN, 0.);
	
		if (debug) dump_matrix(X, MMLEN, MMLEN);
		if (debug) dump_matrix(Y, MMLEN, MMLEN);

		// serial
		gettimeofday(&tvs, NULL);
		dgemm_serial (X, Y, MMLEN, MMLEN, MMLEN, Z);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemm in serial");

		if (debug) dump_matrix(Z, MMLEN, MMLEN);

		// parallel
		gettimeofday(&tvs, NULL);
		dgemm_parallel (X, Y, MMLEN, MMLEN, MMLEN, Z);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemm in parallel");

		if (debug) dump_matrix(Z, MMLEN, MMLEN);

		// parallel v2
		gettimeofday(&tvs, NULL);
		dgemm_parallelv2 (X, Y, MMLEN, MMLEN, MMLEN, Z);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "dgemm in parallelv2");

		if (debug) dump_matrix(Z, MMLEN, MMLEN);

		// post-test
		del_matrix(X);
		del_matrix(Y);
		del_matrix(Z);

	}
	hrulefill();
	{ // convolution

		// data
		double * image = new_matrix(IMLEN, IMLEN);
		double * kernel = new_matrix(KLEN, KLEN);
		double * fmap = new_matrix(FLEN(IMLEN,KLEN), FLEN(IMLEN,KLEN));
		fill_matrix(image, IMLEN, IMLEN, 1.);
		fill_matrix(kernel, KLEN, KLEN, 1.);
		fill_matrix(fmap, FLEN(IMLEN,KLEN), FLEN(IMLEN,KLEN), 0.);

		if (debug) dump_matrix(image, IMLEN, IMLEN);
		if (debug) dump_matrix(kernel, KLEN, KLEN);

		// serial
		gettimeofday(&tvs, NULL);
		conv2_serial (image, kernel, IMLEN, KLEN, fmap);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "conv2 in serial");

		if (debug) dump_matrix(fmap, FLEN(IMLEN,KLEN), FLEN(IMLEN,KLEN));

		// parallel
		gettimeofday(&tvs, NULL);
		conv2_parallel (image, kernel, IMLEN, KLEN, fmap);
		gettimeofday(&tve, NULL);
		timediff (tvs, tve, "conv2 in parallel");

		if (debug) dump_matrix(fmap, FLEN(IMLEN,KLEN), FLEN(IMLEN,KLEN));

		// post-test
		del_matrix(image);
		del_matrix(kernel);
		del_matrix(fmap);

	}
	hrulefill();

	// how long all the benchmarks take
	gettimeofday(&tvt, NULL);
	timediff(tvi, tvt, "All benchmark");

	return 0;
}
