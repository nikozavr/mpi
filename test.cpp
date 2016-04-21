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
	std::ifstream infile("file");
	vector<float> array;

	std::string line;
	while (std::getline(infile, line))
	{
	    std::istringstream iss(line);
	    float a;
	    if (!(iss >> a)) { break; } // error
	    array.push_back(a);
	    // process pair (a,b)
	}

  quickSort(array);
	cout << endl;
	cout << "Result" << endl;
	printArray(array);

	return 1;
}
