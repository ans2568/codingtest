#include <iostream>
#define MAX 1000000000
#define MAX_SIZE 201
using namespace std;
long long DP[MAX_SIZE][MAX_SIZE];
int main() {
  int N, K;
  cin >> N >> K;
  for (int i=0; i<=N; i++)
    DP[i][1] = 1;
  for (int i = 0; i <= K; i++)
    DP[1][i] = i;
  for (int i = 2; i <= N; i++) {
    for (int j = 2; j <= K; j++) {
      DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MAX;
    }
  }
  cout << DP[N][K] << endl;
}