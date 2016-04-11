#include <iostream>
#include <fstream>
#include "lib/quicksort.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main(){
//	const float a[] = { 1, 1.5, 3, 2, 0.8, 4, 2, 3, 0.3};
//	const float a[] = { 1, 1.5, 0.43, 2, 0.8, 0.1, 0.2, 0.4, 0.6};
//	const float a[] = { 1, 0.8, 0.43, 2, 0.8, 0.1, 0.2, 0.4, 0.6};
//	const float a[] = {0.8, 2, 0.9, 1  };

	std::ifstream infile("file");
	vector<float> array;

	std::string line;
	while (std::getline(infile, line))
	{
	    std::istringstream iss(line);
	    float a;
	    if (!(iss >> a)) { break; } // error
	    cout << a << endl;
	    array.push_back(a);
	    // process pair (a,b)
	}

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