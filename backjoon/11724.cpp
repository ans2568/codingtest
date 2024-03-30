#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M, cnt = 0;
vector<vector<int>> graph;
bool visited[MAX];
void bfs(int n) {
  if (visited[n] == true)
    return;
  queue<int> q;
  q.push(n);
  cnt++;
  visited[n] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < graph[now].size(); i++) {
      if (visited[graph[now][i]] == false) {
        visited[graph[now][i]] = true;
        q.push(graph[now][i]);
      }
    }
  }
}

int main() {
  cin >> N >> M;
  graph.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= N; i++)
    bfs(i);
  cout << cnt << "\n";
}
