#include<stdio.h>
#include<omp.h>

int fibonacci(int x) {
	return x < 2 ? 1: (fibonacci(x-1) + fibonacci(x-2));
}

int main () {
	int A [10];
	int sum = 0;
	omp_set_num_threads(10);
#pragma omp parallel
	{
		int id = omp_get_thread_num();
		A[id] = fibonacci (id * 4);
#pragma omp barrier
		printf("%d: %d\n", id, A[id]);
#pragma omp critical
		sum += A[id];
#pragma omp barrier
		printf("%d: %d\n", id, sum);
	}
	
	
	
	
}


