#include<stdio.h>
#include<omp.h>
#define NUM_THREADS 4
#define PAD 8
float seqPi (double step, long from, long to);
static const long num_steps = 100000000;

int main () {
	float  piece[NUM_THREADS][PAD];
	long slice = num_steps /NUM_THREADS;
	double step = 1.0/(double) num_steps;
	
	omp_set_num_threads(NUM_THREADS);
	omp_get_wtime();
	
	// My solution 
#pragma omp parallel
	{
		long from; 
		from = omp_get_thread_num() * slice;
		piece[omp_get_thread_num()][0] = seqPi(step, from , from + slice );
	}
	for(int i = 1 ; i < NUM_THREADS ; i ++) {
		piece[0][0] = piece[0][0] + piece[i][0];
	}
	printf ("Pi:%f %f\n",piece[0][0], omp_get_wtime());
	
	
	// Course guy solution 
	int i, nthreads; 
	double pi, sum[NUM_THREADS][PAD];
#pragma omp parallel
	{
		int i, nth, id;
		double x ;
		id = omp_get_thread_num();
		nth = omp_get_num_threads();
		if (id == 0) nthreads = nth;
		for (i = id, sum[id][0]=0.0; i<num_steps; i=i+nthreads){
			x = (i + 0.5) * step;
			sum[id][0] = sum[id][0] + 4.0/(1.0+x*x);
			
		}
		
		
	}
	pi = 0;
	for(int i = 0 ; i < nthreads ; i ++) {
		pi += sum[i][0];
	}
	printf ("PiPi:%f %f\n", pi, omp_get_wtime());
	
	printf ("Pi:%f %f\n", seqPi(step, 0 , num_steps), omp_get_wtime());
}




float seqPi (double step, long from, long to) {
	double x,  sum = 0.0;
	for (long i = from; i < to ; i++){
		x = (i + 0.5) * step;
		sum = sum + 4.0/(1.0+x*x);
	}
	return sum * step;
}