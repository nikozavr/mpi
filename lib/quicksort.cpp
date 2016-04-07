#include "quicksort.h"
#include <iostream> 

using namespace std;

void swap(float &el1, float &el2){
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
	// return 1 - sorting and parting is complete
	// return 0 - parting is not neccessary - size of array equals 1 or 2
	// return -1 - some errors
	
	// Test print
	cout << endl;
	cout << "Start qs" << endl;
	printArray(array);

	size_t arr_size = array.size();

	if (arr_size > 1){
		size_t half = array.size() / 2;
		cout << half<< endl;

		int i = 0;
		int j = array.size() - 1;
		float op_el = array[half];
		cout << op_el << endl;
		int tes;
		

		do {
			cout << "I b J" << endl;
			while ( (array[i] < op_el) && (i < half) )  i++;
			cout << i << endl;
			while ( (array[j] > op_el) && (j > half)  ) j--;
			cout << j << endl;
			if (i == half){
				half = j;
			} else  if (j == half) {
				half = i;
			}
	 
	    	if (i <= j) {
	      		swap(array[i], array[j]);
	      		i++; j--;
	    	}
		} while ((i < half) || (j > half));

		if(array.size() > 2){
			cout << "Res" << endl;
			printArray(array);

			cout << half << endl;

			rarr1.assign(array.begin(), array.begin() + half);

			cout << "Test"<< endl;
			cout << half << endl;
			rarr2.assign(array.begin() + half , array.end());

			printArray(rarr1);
			printArray(rarr2);

			vector<float> temp11;
			vector<float> temp12;

			vector<float> temp21;
			vector<float> temp22;

			quickSortPart(rarr1, temp11, temp12);
			quickSortPart(rarr2, temp21, temp22);

			for(std::size_t i = 0; i < half; i++){
				array[i] = rarr1[i];
			}

			for (std::size_t i = half; i < array.size(); i++)
			{
				array[i] = rarr2[i-half];
			} 
		}
		
		return 1;
	}

	return 0;
	
}