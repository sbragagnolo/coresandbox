#include<stdio.h>



int main () {
	
	int x, y ; 
	
	x = 1 ;
	y = 2;
	
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf ("x: %d y: %d\n", x, y);
}