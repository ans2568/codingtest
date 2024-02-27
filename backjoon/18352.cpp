#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, K, X;
void bfs(int x);
queue<int> node;
vector<vector<int>> graph;
vector<int> dist;
vector<int> answer;

int main() {
  cin >> N >> M >> K >> X;
  graph.resize(N + 1);
  dist.resize(N+1, -1);
  for (int i = 0; i < M; i++) {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
  }
  bfs(X);
  if (answer.empty())
    cout << -1 << endl;
  else {
    for (auto &a : answer)
      cout << a << endl;
  }
  return 0;
}

void bfs(int x) {
  dist[x] = 0;
  node.push(x);
  while (!node.empty()) {
    int now = node.front();
    node.pop();
    for (int i = 0; i < graph[now].size(); i++) {
        if (dist[graph[now][i]] == -1) {
          dist[graph[now][i]] = dist[now] + 1;
          node.push(graph[now][i]);
        }
    }
  }
  for (int i = 1; i <= N; i++) {
    if (dist[i] == K)
      answer.push_back(i);
  }
}