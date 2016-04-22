#include "quicksort.h"
#include <iostream>

using namespace std;

namespace qs{
	void swap(float &el1, float &el2){
		float temp = el1;
		el1 = el2;
		el2 = temp;
	}

	void printArray(std::vector<float> &array){
		for (vector<float>::const_iterator i = array.begin(); i != array.end(); ++i)
	    	cout << *i << ' ';
	    cout << endl;
	}

	int quickSortPart(std::vector<float> &array, std::vector<float> &rarr1, std::vector<float> &rarr2){
		size_t arr_size = array.size();

		if (arr_size > 1){
			size_t half = array.size() / 2;

			int i = 0;
			int j = array.size() - 1;
			float op_el = array[half];
			int tes;


			do {
				bool need_inc = true;

				while ( (array[i] < op_el) && (i < half) )  i++;

				while ( (array[j] > op_el) && (j > half)  ) j--;

				if (i == half){
					half = j;
					need_inc = false;
				} else  if (j == half) {
					half = i;
					need_inc = false;
				}

		    	if (i <= j) {
		      		swap(array[i], array[j]);
		      		if (need_inc){
		      			i++; j--;
		      		}
		    	}
			} while ((i < half) || (j > half));

			rarr1.assign(array.begin(), array.begin() + half);

			rarr2.assign(array.begin() + half , array.end());


			return 1;
		}

		return 0;

	}

	void quickSort(std::vector<float> &array){
		std::vector<float> v1;
		std::vector<float> v2;
		quickSortPart(array, v1, v2);
			if(v1.size()>1){
				quickSort(v1);
			}
			array.assign(v1.begin(), v1.end());
			if(v2.size()>1){
				quickSort(v2);
			}
			array.insert( array.end(), v2.begin(), v2.end() );
	}
}
