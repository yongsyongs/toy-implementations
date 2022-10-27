// 평균적인 경우 선형 시간 안에 탐색을 완료하는 알고리즘

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

int _Select(int *A, int left, int right, int k) {
    // left ~ right 범위 이내에서 k 번째를 찾는 과정
    // k in [0, right - left]
    int targetIdx = left + k;
    if(left == right) return A[left];

    int mid = Partition(A, left, right, (left + right) / 2);
    if(mid == targetIdx) return A[mid];
    else if(mid < targetIdx) return _Select(A, mid + 1, right, k - (mid - left + 1));
    else return _Select(A, left, mid - 1, k);
}

// 평균적으로 선형 시간 이내에 배열에서 k(k in [0, N))번재로 작은 원소를 찾아낸다.
int AverageLinearSelect(int *A, int N, int k) {
    return _Select(A, 0, N - 1, k);
}

int main() {
    int testCase[20] = {5, 3, 7, 8, 9, 6, 4, 2, 1, 0, 0, 0, 0, 1, 1000, 9, 11, 543, 123, 1000};
    int N = 20;
    for(int i = 0; i < N; i++) {
        int x = AverageLinearSelect(testCase, N, i);
        int y = SelectNumber(testCase, N, i);
        if(x == y) std::cout << "Success" << std::endl;
        else std::cout << "Fail" << std::endl;
    }
}