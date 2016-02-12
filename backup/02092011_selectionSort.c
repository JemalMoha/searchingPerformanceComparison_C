#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define nmax 10000000
//#define nmax 10,000,000
/*
 *  Sorting with selection sort
 *  input = an array
 *  ouput = Sorted array, Increasing
 *
 */
int A[nmax+1];
void selectsort(int n);

int main() {
	int n, i;
	clock_t start, runtime;
	printf("Number of items = ");
	while (scanf("%i", &n)) {
		if (n > nmax) {printf("Number too large. Try again: ");
		continue; 
	}//end of main
	printf("Generating %d random numbers in the range 0..%d.n", n,RAND_MAX);
	for (i = 1; i <= n; i++) A[i] = rand();
		printf("Beginning selection sort of %d items\n", n);

	start = clock();
	selectsort(n);
	runtime = clock() - start;
	printf("Done. Time = %.4f seconds.\n",(double)runtime/(double)CLOCKS_PER_SEC);
	printf("Number of items = ");
	}
	return 0;
}//end of main


void selectsort(int n) {
/* Arrange elements of array A[1..n] into increasing */
/* order using the selection sort method.*/
	int i, j, amin, imin, atmp;
	for (i = 1; i < n; i++) {
	amin = A[i]; imin = i;
	for (j = i+1; j <= n; j++)
	if (A[j] < amin) {
		amin = A[j]; imin = j;
	}//end of if
	A[imin] = A[i]; A[i] = amin;
	}//end of outer for
}//end of selectsort

