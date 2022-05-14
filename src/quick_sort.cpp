#include "assignment/quick_sort.hpp"

#include <cassert>  // assert

#include "assignment/partitioning.hpp"  // partition, median_of_three

namespace assignment {

  void QuickSort::Sort(std::vector<int>& arr) const {
    quick_sort(arr, 0, static_cast<int>(arr.size()) - 1);
  }

  void QuickSort::quick_sort(std::vector<int>& arr, int start, int stop) const {
    assert(start >= 0);

    if (start >= stop) {
      return;
    }

    // вычисляем индекс опорного элемента ... median_of_three ...
    int med_ind = median_of_three(arr, start, stop);
    int pivot_index = partition(arr, start, stop, med_ind);
    quick_sort(arr, start, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, stop);

    // производим разбиение относительно опорного элемента ...  partition ...
    // рекурсивно повторяем процедуру над левой и правой частью ...
  }

}  // namespace assignment