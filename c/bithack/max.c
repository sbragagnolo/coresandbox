#include<stdio.h>



int main ( void ) {
	int x, y;
	x = 3;
	y = 4;
	
	
	// max 
	printf ("Max :%d \n", y ^((x^y) & -(x>y)));
}