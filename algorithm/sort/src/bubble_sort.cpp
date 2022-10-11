#include <iostream>
#include "utils.h"

void BubbleSort(int *A, int N) {
    for(int i = N - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(A[j] > A[j + 1]) Swap(A, j, j + 1);
        }
    }
}

int main() {
    int testCase[20] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000};
    BubbleSort(testCase, 20);
    if(IsSorted(testCase, 20)) std::cout << "Success" << std::endl;
    else std::cout << "Fail" << std::endl;
}