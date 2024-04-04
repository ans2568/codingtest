#include <iostream>

using namespace std;

int N, M;
int graph[9];
bool visited[9] = {false, };

void dfs(int n) {
  if (n == M) {
    for (int i = 0; i < M; i++)
      cout << graph[i] << ' ';
    cout << "\n";
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      graph[n] = i;
      dfs(n + 1);
      visited[i] = false;
    }
  }
}

int main() {
  cin >> N >> M;
  dfs(0);
}