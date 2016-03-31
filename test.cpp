#include <iostream>
#include "lib/quicksort.h"
#include <vector>


int main(){
	const float a[] = { 1, 1.3, 1.5, 0.9, 0.1, 0.2, 0.4, 0.6};

   	std::vector<float> array ( a,a + sizeof( a ) / sizeof( a[0] ) );
	//std::vector<float> array = {213.324,423.4,2.34,543.345,345.234};
	std::cout << quicksort(array, array, array) << std::endl;
	return 1;
}