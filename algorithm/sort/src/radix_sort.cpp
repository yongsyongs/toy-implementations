#include <iostream>
#include <queue>
#include "utils.h"

void RadixSort(int *A, int N, int K) {
    int exp = 1;
    std::queue<int> queue[10];
    for(int k = 0; k < K; k++) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            int x = (A[i] / exp) % 10;
            queue[x].push(A[i]);
        }
        for(int i = 0; i < 10; i++) {
            while(queue[i].size()) {
                A[cnt++] = queue[i].front();
                queue[i].pop();
            }
        }
        exp *= 10;
    }
}

int main() {
    int testCase[20] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000};
    RadixSort(testCase, 20, 4);
    if(IsSorted(testCase, 20)) std::cout << "Success" << std::endl;
    else std::cout << "Fail" << std::endl;
}