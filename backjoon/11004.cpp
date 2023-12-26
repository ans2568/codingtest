#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &A, int S, int E, int K);
int partition(vector<int> &A, int S, int E);
void swap(vector<int> &A, int S, int E);

int main() {
  int N = 5, K = 2;
  vector<int> A = {4, 1, 2, 3, 5};
  quick_sort(A, 0, N - 1, K);
  cout << A.at(K - 1) << endl;
  return 0;
}

void quick_sort(vector<int> &A, int start, int end, int K) {
  int pivot = partition(A, start, end);
  if (pivot == K)
    return;
  else if (K < pivot) {
    quick_sort(A, start, pivot - 1, K);
  } else {
    quick_sort(A, pivot + 1, end, K);
  }
}

int partition(vector<int> &A, int start, int end) {
  if (start + 1 == end) {
    if (A.at(start) > A.at(end))
      swap(A, start, end);
    return end;
  }

  int M = (start + end) / 2;
  swap(A, start, M);
  int pivot = A.at(start);
  int i = start + 1;
  int j = end;
  while (i <= j) {
    while (j > 0 && A.at(j) > pivot)
      j--;
    while (i < A.size() - 1 && A.at(i) < pivot)
      i++;
    if (i <= j)
      swap(A, i++, j--);
  }
  A.at(start) = A.at(j);
  A.at(j) = pivot;
  return j;
}

void swap(vector<int> &A, int S, int E) {
  int temp = A.at(S);
  A.at(S) = A.at(E);
  A.at(E) = temp;
}