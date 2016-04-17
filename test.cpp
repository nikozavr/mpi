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
	vector<float> res;

	std::string line;
	while (std::getline(infile, line))
	{
	    std::istringstream iss(line);
	    float a;
	    if (!(iss >> a)) { break; } // error
	    array.push_back(a);
	    // process pair (a,b)
	}

  res.insert(res.end(), array.begin(), array.end());

	cout << endl;
	cout << "Result" << endl;
	printArray(res);

	return 1;
}
