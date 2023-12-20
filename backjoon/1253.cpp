#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// backjoon 1253 problem
// https://www.acmicpc.net/problem/1253

int main() {
  int N;
  cin >> N;
  vector<int> A(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());

  // two pointer algorithm
  int count = 0;
  for (int k = 0; k < N; k++) {
    long find = A.at(k);
    int i = 0;     // start
    int j = N - 1; // end

    while (i < j) {
      if (A.at(i) + A.at(j) == find) {
        if (i != k && j != k) {
          count++;
          break;
        } else if (i == k) {
          i++;
        } else if (j == k) {
          j--;
        }
      } else if (A.at(i) + A.at(j) < find) {
        i++;
      } else if (A.at(i) + A.at(j) > find) {
        j--;
      }
    }
  }
  cout << count << endl;

  return 0;
}