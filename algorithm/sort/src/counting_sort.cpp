#include <iostream>
#include "utils.h"

void CountingSort(int *A, int N, int K) {
    int cnt = 0;
    int *counts = new int[K + 1];
    for(int i = 0; i < N; i++) counts[A[i]]++;
    for(int i = 0; i <= K; i++) {
        while(counts[i]--) A[cnt++] = i;
    }
}

int main() {
    int testCase[20] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000};
    CountingSort(testCase, 20, 1000);
    if(IsSorted(testCase, 20)) std::cout << "Success" << std::endl;
    else std::cout << "Fail" << std::endl;
}