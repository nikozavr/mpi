#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

namespace qs {

  int quickSortPart(std::vector<float> &array, std::vector<float> &rarr1, std::vector<float> &rarr2);

  void quickSort(std::vector<float> &array);

  void printArray(std::vector<float> &array);

}

#endif
