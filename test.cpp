#include <iostream>
#include "lib/quicksort.h"
#include <vector>

using namespace std;

int main(){
//	const float a[] = { 1, 1.5, 3, 2, 0.8, 4, 2, 3, 0.3};
	const float a[] = { 1, 1.5, 0.43, 2, 0.8, 0.1, 0.2, 0.4, 0.6};
//	const float a[] = { 1, 0.8, 0.43, 2, 0.8, 0.1, 0.2, 0.4, 0.6};
//	const float a[] = {0.8, 2, 0.9, 1  };

   	vector<float> array ( a,a + sizeof( a ) / sizeof( a[0] ) );
   	vector<float> v1;
   	vector<float> v2;

	quickSortPart(array, v1, v2);

	cout << endl;
	cout << "Result" << endl;
	printArray(array);
	printArray(v1);
	printArray(v2);

	

	return 1;
}