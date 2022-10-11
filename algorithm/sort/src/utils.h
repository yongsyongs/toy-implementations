#ifdef utils_H
#else
#define utils_H
void Swap(int *A, int i, int j);
void CopyArray(int *A, int *B, int left, int right);
int ArgMax(int *A, int left, int right);
bool IsSorted(int *A, int N);
#endif