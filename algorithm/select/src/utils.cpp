#include <algorithm>
#include "utils.h"

void Swap(int *A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void CopyArray(int *A, int *B, int left, int right) {
    for(int i = left; i <= right; i++)
        B[i] = A[i];
}

int SelectNumber(int *A, int N, int k) {
    int *B = new int[N];
    CopyArray(A, B, 0, N - 1);

    std::sort(A, A + N);
    return A[k];
}