#include <iostream>

using namespace std;
int DP[101][10]; // [길이][끝자리 수]

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= 9; i++) {
    DP[1][i] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j == 0)
        DP[i][j] = DP[i - 1][j + 1];
      else if (j == 9)
        DP[i][j] = DP[i - 1][j - 1];
      else
        DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1];
      DP[i][j] %= 1000000000;
    }
  }
  int sum = 0;
  for (int i = 0; i <= n; i++)
    sum = (sum + DP[n][i]) % 1000000000;
  cout << sum << "\n";
}