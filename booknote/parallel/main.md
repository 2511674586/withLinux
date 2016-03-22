Parallel Computing and Implementations
---

Extra programs  
[trap1.c, float number ignores addition of 1.0](./omp/trap1.c)  
[benchmark.c, parallel computing benchmark](./omp/benchmark.c)  


> 迟学斌，并行计算与实现技术，科学出版社

> MPI, when multiple computers contructing an cluster  
> OpenMP, when  single computer with multiple processors  
> CUDA, large scale, fine-grained computation  

## MPI

+placeholder

## OpenMP

#### parallel structure

```
#pragma omp parallel ...
```
the code block in the structure will be ran by several threads.

#### workload sharing structure

* for
```
#pragma omp for ...


(1)
#pragma omp parallel ...
{
	#pragma omp for ...
}

(2)
#pragma omp parallel for ...

(1) is equivalent to (2).
```

* sections
```
#pragma omp parallel sections ...
{
	#pragma omp section ...
	{
		...
	}
	#pragma omp section ...
	{
		...
	}
}
```

* single
```
#pragma omp single ...
{
	...
}
```

* workshare is only used in Fortran.

* master

* critical, for avoiding race condition
```
#pragma omp critical [(name)]
{
	...
}
```

* barrier for syncing all threads
```
#pragma omp barrier
```

* atomic
```
#pragma omp atomic [read|write|update|capture]
expression
```

* flush to flush changes
```
#pragma omp flush [(list)]
```

* ordered
```
#pragma omp parallel for ordered schedule(dynamic)
for (i = 0; i < 50; i += 5) {
	#pragma omp ordered
	printf("%d\n", i);
}
```

* threadprivate, copyin

* copyprivate

#### data sharing

* shared
```
#pragma omp parallel for shared(a, b)
for (i = 0; i < n; i++)
	b[i] = a[i];
```

* private
```
#pragma omp parallel private(tid, i) shared(a, n)
{
  tid = omp_get_thread_num();
  for (i = 0; i < n; i++)
    matrix[tid][i] = 1;
    // note, please check matrix boundary, i.e. the reference tid may exceeds boundary
}
```

* firstprivate  

* lastprivate  

* default  

* reduction  

```
int sum = 0;
#pragma omp parallel reduction (+:sum) private(i, tid)
{
	tid = omp_get_thread_num();
	for (i = 0; i < n; i++)
		sum = sum + a[tid][i];
	// note, watch out for boundary of a[][]
}
```

#### other clauses

* num_threads, declaring how many threads you want to use  

* nowait  

* collapse
```
// squash (for k) and (for j) together, tasks are assigned automatically
#pragma omp for collapse(2) private(i, j, k)
for (k = 0; k < n; k++)
for (j = 0; j < n; j++)
	for (i = 0; i < n; i++)
		bar(...)
```

#### Tasking structure

* task
```
void
traverse (struct tree * t)
{
	if (t->left) { // t is firstprivate by default
#pragma omp task
		traverse(t->left);
	}
	if (t->right) { // t is firstprivate by default
#pragma omp task
		traverse(t->right);
	}
	process(t);
}
```

* taskwait

* taskyield  

#### OpenMP runtime lib

runtime

* `omp_set_num_threads`, usage is outside of omp block

* `omp_get_num_threads`

* `omp_get_max_threads`

* `omp_get_thread_num`

* `omp_get_num_procs`

* `omp_in_parallel`

* `omp_{g,s}et_dynamic`

* `omp_{g,s}et_nested`

* `omp_{g,s}et_schedule`

...

locks  

* `omp_init_lock`

* `omp_destroy_lock`

* `omp_set_lock`

* `omp_unset_lock`

* `omp_test_lock`

time, wall clock time

* `double omp_get_wtime(void);`
* `omp_get_wtick`

## CUDA

+ placeholder

Other Reference  
---

1. http://openmp.org  
1. BOOK: Using OpenMP
1. code example: http://openmp.org/examples/Using-OpenMP-Examples-Distr.zip  
