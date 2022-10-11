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

int ArgMax(int *A, int left, int right) {
    if(left >= right) return left;

    int arg = left;
    for(int i = left; i <= right; i++)
        arg = A[arg] < A[left] ? left : arg;
    
    return arg;
}

bool IsSorted(int *A, int N) {
    for(int i = 0; i < N - 1; i++) {
        if(A[i] > A[i] + 1) return false;
    }
    return true;
}