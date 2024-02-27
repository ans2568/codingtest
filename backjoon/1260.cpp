#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
void dfs(int num);
void bfs(int num);
int depth = 0;

int main() {
  int V;
  cin >> N >> M >> V;
  graph.resize(N + 1);
  visited.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }
  dfs(V);
  cout << endl;
  visited = vector<bool>(N+1, false);
  bfs(V);
  cout << endl;

  return 0;
}

void dfs(int num) {
  if (visited[num] == true)
    return;
  visited[num] = true;
  if (depth == 0)
    cout << num << " ";
  sort(graph[num].begin(), graph[num].end());
  for (int i = 0; i < graph[num].size(); i++) {
    if (visited[graph[num][i]] == false) {
      cout << graph[num][i] << " ";
      depth += 1;
      dfs(graph[num][i]);
    } else continue;
  }
}

void bfs(int num) {
    queue<int> queue;
    queue.push(num);
    cout << num << " ";
    visited[num] = true;
    while (!queue.empty()) {
      int now = queue.front();
      queue.pop();
      for (int i = 0; i < graph[now].size(); i++) {
        if (visited[graph[now][i]] == false) {
          visited[graph[now][i]] = true;
          cout << graph[now][i] << " ";
          queue.push(graph[now][i]);
        }
      }
    }
}