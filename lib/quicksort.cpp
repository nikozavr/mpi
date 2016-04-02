#include "quicksort.h"
#include <iostream> 

using namespace std;

void swap(float el1, float el2){
	cout << "Test swap" << endl;
	float temp = el1;
	el1 = el2;
	el2 = temp; 
}

void printArray(vector<float> &array){
	for (vector<float>::const_iterator i = array.begin(); i != array.end(); ++i)
    	cout << *i << ' ';
    cout << endl;
}


int quickSortPart(std::vector<float> &array, std::vector<float> &rarr1, std::vector<float> &rarr2){
	printArray(array);
	size_t half = array.size() / 2;

	int i = 0;
	int j = array.size() - 1;
	float op_el = array[half];

	cout << op_el << endl;
	
	do {
		cout << "First test" << endl;
		cout << endl;
		cout << array[i] << endl;
		cout << op_el << endl;
		while ( array[i] < op_el ) {
			i++;
			cout << array[i] << endl;
			cout << op_el << endl;
		}
		cout << "Between" << endl;
		while ( array[j] > op_el ) j--;
		cout << "Test" << endl;
    	if (i <= j) {
      		swap(array[i], array[j]);
      		i++; j--;
    	}
    	cout << "Test after swap" << endl;
	} while (i <= j);

	
	vector<float> t1 (half, 0);
	rarr1 = t1;

	for(std::size_t i = 0; i < half; i++){
		rarr1[i] = array[i];
	}

	
	vector<float> t2(array.size() - half, 0);
	rarr2 = t2;

	for (std::size_t i = half; i < array.size(); i++)
	{
		rarr2[i - half] = array[i];
	}

	
	return 1;
}