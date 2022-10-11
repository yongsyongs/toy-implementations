#include <iostream>
#include "utils.h"

void _Merge(int *A, int *B, int left, int right, int mid) {
    int iLeft = left;
    int iRight = mid + 1;
    int iMerged = left;

    while(iMerged <= right) {
        if(iLeft > mid) B[iMerged++] = A[iRight++];
        else if(iRight > right) B[iMerged++] = A[iLeft++];
        else if(A[iLeft] > A[iRight]) B[iMerged++] = A[iRight++];
        else B[iMerged++] = A[iLeft++];
    }

    CopyArray(A, B, left, right);
}

void _MergeSort(int *A, int *B, int left, int right) {
    if(left == right) return;
    int mid = (left + right) / 2;

    _MergeSort(A, B, left, mid);
    _MergeSort(A, B, mid + 1, right);

    _Merge(A, B, left, right, mid);
}

void MergeSort(int *A, int N) {
    int *B = new int[N];
    CopyArray(A, B, 0, N - 1);

    _MergeSort(A, B, 0, N - 1);
}

int main() {
    int testCase[20] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000};
    MergeSort(testCase, 20);
    if(IsSorted(testCase, 20)) std::cout << "Success" << std::endl;
    else std::cout << "Fail" << std::endl;
}