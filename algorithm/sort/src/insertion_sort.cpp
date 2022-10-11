#include <iostream>
#include "utils.h"

void InsertionSort(int *A, int N) {
    for(int i = 1; i < N; i++) {
        int item = A[i];
        int insertingPoint;
        for(insertingPoint = 0; insertingPoint < i; insertingPoint++) {
            if(A[insertingPoint] > item) break;
        }
        for(int j = i - 1; j >= insertingPoint; j--) A[j + 1] = A[j];

        A[insertingPoint] = item;
    }
}

int main() {
    int testCase[20] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000};
    InsertionSort(testCase, 20);
    if(IsSorted(testCase, 20)) std::cout << "Success" << std::endl;
    else std::cout << "Fail" << std::endl;
}