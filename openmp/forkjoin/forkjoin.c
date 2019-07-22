#include<stdio.h>
#include<omp.h>



int pooh (int id) ;

int main () {	
	omp_set_num_threads(10);
	printf("\nFORK\n");
#pragma omp parallel 
	{
		int ID = omp_get_thread_num();
		pooh(ID);
	}
	printf("\nJOIN\n");
	
}

int pooh (int id) {
	printf ("\t%d", id);
	return 1 ;
}