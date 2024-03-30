#include <iostream>

using namespace std;

int A[1000], DP[1000];
int main() {
  int N, cnt = 0;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    DP[i] = 1;
    cin >> A[i];
    for (int j = i - 1; j >= 1; --j) {
      if (A[i] > A[j]) {
        DP[i] = max(DP[i], DP[j] + 1);
      }
    }
    cnt = max(DP[i], cnt);
  }
  cout << cnt << endl;
}
