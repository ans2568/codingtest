#include <iostream>
using namespace std;
int N;
int Card[1001];
int DP[1001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> Card[i];
  }
  DP[1] = Card[1];
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      if (DP[i] == 0)
        DP[i] = min(10000 * 1000, DP[i - j] + Card[j]);
      else
        DP[i] = min(DP[i], DP[i - j] + Card[j]);
    }
  }
  cout << DP[N] <<"\n";
  return 0;
}