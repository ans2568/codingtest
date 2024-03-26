#include <iostream>

using namespace std;

long DP[91][2]; // [자리 수][1 or 0]

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  DP[1][0] = 0;
  DP[1][1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      if (j == 1)
        DP[i][j] = DP[i - 1][0];
      else
        DP[i][j] = DP[i - 1][0] + DP[i - 1][1];
    }
  }
  long result = 0;
  for (int i = 0; i <= 1; i++) {
    result += DP[n][i];
  }
  cout << result << "\n";
}