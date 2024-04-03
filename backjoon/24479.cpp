#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
bool visited[100001];
vector<int> result;
int cnt = 1;

void dfs(int n) {
  if (visited[n])
    return;
  visited[n] = true;
  result[n] = cnt++;
  sort(graph[n].begin(), graph[n].end());
  for (int i = 0; i < graph[n].size(); i++) {
    int next = graph[n][i];
    dfs(next);
  }
}
int main() {
  int N, M, R;
  cin >> N >> M >> R;
  graph.resize(N + 1);
  result= vector<int>(N+1, 0);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(R);
  for (int i=1; i<result.size(); i++)
    cout << result[i] << "\n";
}