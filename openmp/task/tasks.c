#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int fibonacci(int n) {
	int x, y;
	
	if (n < 2) return 1;
	
#pragma omp task shared(x)
	{
		x = fibonacci(n-1);
	}
#pragma omp task shared(y)
	{
		y = fibonacci(n-2);
	}
#pragma omp taskwait
	return x + y; 
}

int main (int argc, char** argv) {
	int fib;
	
	fib = (argc >1)? strtol(argv[1], NULL, 10) : 30; 
	
#pragma omp parallel
#pragma omp single
	{
		printf("Fib(%d): %d\n",fib , fibonacci(fib));
	}
	
	
	
	
}


