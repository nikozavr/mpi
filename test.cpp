#include <iostream>
#include "lib/quicksort.h"
#include <vector>

using namespace std;

int main(){
	const float a[] = { 1, 1.3, 1.5, 2, 32.1, 0.1, 0.2, 0.4, 0.6};

   	vector<float> array ( a,a + sizeof( a ) / sizeof( a[0] ) );
   	vector<float> v1;
   	vector<float> v2;

   
	cout << "Test" << endl;
	printArray(array);
	quickSortPart(array, v1, v2);

	cout << endl;
	cout << "Result" << endl;
	printArray(array);
	printArray(v1);
	printArray(v2);

	return 1;
}