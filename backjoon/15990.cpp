#include <iostream>
using namespace std;

long long DP[100001][4];
int main() {
  int n;
  cin >> n;
  DP[1][1] = 1;
  DP[2][2] = 1;
  DP[3][1] = 1;
  DP[3][2] = 1;
  DP[3][3] = 1;
  for (int i = 4; i < 100001; i++) {
    DP[i][1] = (DP[i - 1][2] + DP[i - 1][3]) % 1000000009;
    DP[i][2] = (DP[i - 2][1] + DP[i - 2][3]) % 1000000009;
    DP[i][3] = (DP[i - 3][1] + DP[i - 3][2]) % 1000000009;
  }
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    long long sum = 0;
    sum = (DP[in][1] + DP[in][2] + DP[in][3]) % 1000000009;
    cout << sum << endl;
  }
}