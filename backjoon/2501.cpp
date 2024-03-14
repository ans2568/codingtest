#include <iostream>

using namespace std;

int N, K;
int main() {
  cin >> N >> K;
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (N % i == 0) {
      cnt++;
      if (cnt == K)
        cout << i << endl;
    }
  }
  if (cnt < K)
    cout << 0 << endl;
  return 0;
}