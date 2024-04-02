#include <iostream>
#include <vector>
#define NM_MAX 100000
using namespace std;
vector<int> W;
int N, M, cnt = 0;
int main(int argc, char **argv) {
  cin >> N >> M;
  W.resize(N + 1);
  vector<bool> is_best(N + 1, 1);
  for (int i = 1; i <= N; i++) {
    cin >> W[i];
  }
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    if (W[a] > W[b]) {
      is_best[b] = 0;
    } else if (W[a] < W[b]) {
      is_best[a] = 0;
    } else {
      is_best[a] = 0;
      is_best[b] = 0;
    }
  }
  for (int i = 1; i < is_best.size(); i++) {
    if (is_best[i] > 0)
      cnt++;
  }
  cout << cnt << endl;

  return 0;
}