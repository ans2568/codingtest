#include <iostream>
#define endl "\n"
#define MAX 1010
using namespace std;
int N;
int Card[MAX];
int DP[MAX];

void Input() {
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> Card[i];
}

void Solution() {
  DP[1] = Card[1];
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      DP[i] = max(DP[i], DP[i - j] + Card[j]);
    }
  }
  cout << DP[N] << endl;
}

void Solve() {
  Input();
  Solution();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
  return 0;
}