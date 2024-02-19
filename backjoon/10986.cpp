#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // 입력 선언
  int N, M;
  cin >> N >> M;

  vector<long> S(N, 0);
  vector<long> C(M, 0);
  cin >> S[0];

  for (int i = 1; i < N; i++) {
    int temp = 0;
    cin >> temp;
    S[i] = S[i-1] + temp;
  }
  long cnt = 0;
  for (int i = 0; i < N; i++) {
    int remain = S[i] % M;
    if (remain == 0)
      cnt++;
    C[remain]++;
  }
  for (int i = 0; i < M; i++) {
    if (C[i] > 1)
      cnt = cnt + (C[i] * (C[i] - 1) / 2);
  }
  cout << cnt <<endl;
  return 0;
}