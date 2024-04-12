#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int N, M;
bool visited[101], visited2[101];
vector<vector<int>> graph;
vector<vector<int>> graph2;

void bfs(int n) {
  queue<int> q;
  q.push(n);
  visited[n] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < graph[now].size(); ++i) {
      if (visited[graph[now][i]])
        continue;
      visited[graph[now][i]] = true;
      q.push(graph[now][i]);
    }
  }
}
void bfs2(int n) {
  queue<int> q;
  q.push(n);
  visited2[n] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < graph2[now].size(); ++i) {
      if (visited2[graph2[now][i]])
        continue;
      visited2[graph2[now][i]] = true;
      q.push(graph2[now][i]);
    }
  }
}

int main() {
  cin >> N >> M;
  graph.resize(N + 1);
  graph2.resize(N + 1);
  for (int i = 0; i < M; ++i) {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph2[e].push_back(s);
  }
  for (int i = 1; i <= N; ++i) {
    memset(visited, false, sizeof(visited));
    memset(visited2, false, sizeof(visited2));
    int cnt = 0;
    bfs(i);
    bfs2(i);
    for (int j = 1; j <= N; ++j) {
      if (visited[j] || visited2[j])
        cnt += 1;
    }
    cout << N - cnt << "\n";
  }
  return 0;
}