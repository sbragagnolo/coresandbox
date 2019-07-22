#include<stdio.h>
#include<omp.h>

int fibonacci(int x) {
	return x < 2 ? 1: (fibonacci(x-1) + fibonacci(x-2));
}

int main () {
	
#pragma omp parallel for
	{
		for (int i = 0 ; i < 100 ; i ++) {
			printf("Hello world%d %d \n", i, omp_get_thread_num());
		}
	}
	
	
	
	
}


