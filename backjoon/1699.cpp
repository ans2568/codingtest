#include <iostream>
#define MAX 100001
using namespace std;
int DP[MAX];
int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    DP[i] = i;
    for (int j = 1; j * j <= i; j++) {
      DP[i] = min(DP[i], DP[i-j*j] + 1);
    }
  }
  cout << DP[N] << "\n";
}