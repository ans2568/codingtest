#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> result_dfs, result_bfs;
vector<bool> visited;
int n, m, v;

void dfs(int node) {
  if (visited[node] == true)
    return;
  visited[node] = true;
  result_dfs.push_back(node);
  sort(graph[node].begin(), graph[node].end());
  for (int i = 0; i < graph[node].size(); i++) {
    dfs(graph[node][i]);
  }
}

void bfs(int node) {
  queue<int> q;
  visited[node] = true;
  q.push(node);
  while (!q.empty()) {
    int next = q.front();
    q.pop();
    result_bfs.push_back(next);
    sort(graph[next].begin(), graph[next].end());
    for (int i = 0; i < graph[next].size(); i++) {
      if (visited[graph[next][i]] == true)
        continue;
      else {
        visited[graph[next][i]] = true;
        q.push(graph[next][i]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> v;
  graph.resize(n + 1);
  visited = vector<bool>(n+1, false);
  for (int i = 0; i < m; i++) {
    int start, end;
    cin >> start >> end;
    graph[start].push_back(end);
    graph[end].push_back(start);
  }
  dfs(v);
  for (auto &res : result_dfs)
    cout << res << " ";
  cout << "\n";

  visited = vector<bool>(n + 1, false);
  bfs(v);
  for (auto &res : result_bfs)
    cout << res << " ";
  cout << "\n";
}