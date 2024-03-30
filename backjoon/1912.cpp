#include <iostream>
#define MAX_SIZE 100001
using namespace std;
int A[MAX_SIZE], DP[MAX_SIZE];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    DP[i] = A[i];
  }
  int maxsum = DP[0];
  for (int i = 1; i < n; i++) {
    DP[i] = max(DP[i - 1] + A[i], DP[i]);
    maxsum = max(DP[i], maxsum);
  }
  cout << maxsum << "\n";
}