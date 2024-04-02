#include <iostream>
#include <vector>

using namespace std;
vector<int> n, m;
int graph[3001][3001];
int main(int argc, char **argv) {
  int N, M, K;
  cin >> N >> M >> K;
  n.resize(N);
  m.resize(M);
  for (int i = 0; i < N; i++) {
    cin >> n[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> m[i];
  }
  int max_val = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (n[i - 1] == m[j - 1]) {
        graph[i][j] = graph[i - 1][j - 1] + 1;
      }
      max_val = max(max_val, graph[i][j]);
    }
  }
  cout << max_val << endl;

  return 0;
}