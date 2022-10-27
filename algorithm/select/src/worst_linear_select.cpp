// 최악의 경우에도 선형 시간 안에 탐색을 완료하는 알고리즘

#include <iostream>
#include <algorithm>
#include "utils.h"

int Partition(int *A, int left, int right, int pivotValue) {
    int partitioningIndex = left;

    for(int i = left; i < right; i++) {
        if(A[right] != pivotValue && A[i] == pivotValue) Swap(A, i, right);
        if(A[i] < pivotValue) Swap(A, i, partitioningIndex++);
    }
    Swap(A, partitioningIndex, right);
    return partitioningIndex;
}

int _Select(int *A, int left, int right, int k) {
    int N = right - left + 1;
    if(N == 1) return A[left];
    else if(N <= 5) {
        int *B = new int[N];
        int _idx = 0;
        for(int i = 0; i < N; i++) B[i] = A[i + left];
        std::sort(B, B + N);
        return B[k];
    }

    int targetIdx = left + k;

    int groupNum = N / 5 + (N % 5 == 0 ? 0 : 1);
    int *medians = new int[groupNum];
    for(int i = 0; i < groupNum; i++) {
        int l = left + 5 * i;
        int r = left + 5 * i + 4;
        if(r > right) r = right;
        int m = (r - l) / 2;
        medians[i] = _Select(A, l, r, m);
    }

    int M = _Select(medians, 0, groupNum - 1, groupNum / 2);
    int pivotIndex = Partition(A, left, right, M);
    
    if(pivotIndex == targetIdx) return A[pivotIndex];
    else if(pivotIndex < targetIdx) return _Select(A, pivotIndex + 1, right, k - (pivotIndex - left + 1));
    else return _Select(A, left, pivotIndex - 1, k);
}

// 최악의 경우에도 반드시 선형 시간 이내에 배열에서 k(k in [0, N))번재로 작은 원소를 찾아낸다.
int LinearSelect(int *A, int N, int k) {
    return _Select(A, 0, N - 1, k);
}

int main() {
    int testCase[21] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000, 100};
    int N = 21;
    for(int i = 0; i < N; i++) {
        int x = LinearSelect(testCase, N, i);
        int y = SelectNumber(testCase, N, i);
        if(x == y) std::cout << "Success" << std::endl;
        else std::cout << "Fail" << std::endl;
    }
}