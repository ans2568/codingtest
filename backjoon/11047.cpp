#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int N, K;

int main() {
  freopen("../input.txt", "r", stdin);
  cin >> N >> K;
  vector<int> vec(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end(), greater<>());
  int cnt = 0;
  for (int i = 0; i < vec.size(); ++i) {
    while (K - vec[i] >= 0) {
      cnt++;
      K -= vec[i];
    }
  }
  cout << cnt << endl;
  return 0;
}