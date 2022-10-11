#include <iostream>
#include "utils.h"

void Heapify(int *A, int k, int N) {
    // indexing for k starts from 1
    int leftChild = 2 * k;
    int rightChild = leftChild + 1;
    int smaller;
    if(rightChild <= N) smaller = A[leftChild - 1] > A[rightChild - 1] ? rightChild : leftChild;
    else if(leftChild <= N) smaller = leftChild;
    else return;

    if(A[k - 1] > A[smaller - 1]) {
        Swap(A, k - 1, smaller - 1);
        Heapify(A, smaller, N);
    }
}

void BuildHeap(int *A, int N) {
    for(int i = N / 2; i > 0; i--) {
        Heapify(A, i, N);
    }
}

void HeapSort(int *A, int N) {
    BuildHeap(A, N);
    for(int i = N; i > 1; i--) {
        Swap(A, 0, i - 1);
        Heapify(A, 1, i - 1);
    }
    for(int i = 0; i < N / 2; i++) Swap(A, i, N - i - 1);
}

int main() {
    int testCase[20] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000};
    HeapSort(testCase, 20);
    if(IsSorted(testCase, 20)) std::cout << "Success" << std::endl;
    else std::cout << "Fail" << std::endl;
}