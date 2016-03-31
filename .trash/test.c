#include <stdio.h>
#include "quicksort.h"

void main(){
	float array[] = {13.432,232.23,234.23,342.34,23.43,234.2,32.23};
	int t = quicksort(array, array, array);
	printf("%d", t);
}