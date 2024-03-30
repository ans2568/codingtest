#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int A[1000], DP[1000];
vector<int> result;
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
  int idx = 0;
  cout << cnt << endl;
  for (int i = N; i >= 1; i--) {
    if (DP[i] == cnt) {
      result.push_back(A[i]);
      cnt--;
    }
  }
  reverse(result.begin(), result.end());
  for (auto &res : result)
    cout << res << " ";
  cout << "\n";
}
