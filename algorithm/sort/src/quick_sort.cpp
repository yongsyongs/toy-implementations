#include <iostream>
#include "utils.h"

int Partition(int *A, int left, int right, int pivot) {
    int pivotValue = A[pivot];
    int partitioningIndex = left;
    Swap(A, right, pivot);

    for(int i = left; i < right; i++) {
        if(A[i] < pivotValue) Swap(A, i, partitioningIndex++);
    }
    Swap(A, partitioningIndex, right);
    return partitioningIndex;
}

void _QuickSort(int *A, int left, int right) {
    if(left >= right) return;
    int pivot = (left + right) / 2;
    int newPivot = Partition(A, left, right, pivot);
    _QuickSort(A, left, newPivot - 1);
    _QuickSort(A, newPivot + 1, right);
}

void QuickSort(int *A, int N) {
    _QuickSort(A, 0, N - 1);
}

int main() {
    int testCase[20] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000};
    QuickSort(testCase, 20);
    if(IsSorted(testCase, 20)) std::cout << "Success" << std::endl;
    else std::cout << "Fail" << std::endl;
}