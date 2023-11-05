#include <algorithm>
#include <iostream>

int partition(int* arr, int left, int right) {
    int pivot = arr[right];
    int left_mark = (left - 1);

    for (int index = left; index <= right - 1; index++) {
        if (arr[index] > pivot) {
          left_mark++;
            std::swap(arr[left_mark], arr[index]);
        }
    }
    std::swap(arr[left_mark + 1], arr[right]);
    return (left_mark + 1);
}

void quick_sort(int* arr, int left, int right) {
    if (left < right) {
        int boundary = partition(arr, left, right);
        quick_sort(arr, left, boundary - 1);
        quick_sort(arr, boundary + 1, right);
    }
}

void sort(int* arr, int length) {
  quick_sort(arr, 0, length-1);
}
