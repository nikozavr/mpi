#include "quicksort.h"

int quickSortPart(std::vector<float> &array, std::vector<float> &rarr1, std::vector<float> &rarr2){
	int op_in = array.size >> 1;

	int i = 0;
	int j = array.size() - 1;
	float op_el = array[op_in]
	do {
		while ( array[i] < op_el ) i++;
		while ( array[j] > op_el ) j--;

    	if (i <= j) {
      		temp = array[i]; array[i] = array[j]; array[j] = temp;
      		i++; j--;
    	}

	} while (i <= j)

// fill
	std::size_t const half_size = array.size() / 2;
	std::vector<int> split_lo(lines.begin(), lines.begin() + half_size);
	std::vector<int> split_hi(lines.begin() + half_size, lines.end());

	return 1;
}