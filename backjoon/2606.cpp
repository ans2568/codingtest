#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, cnt = 0;
vector<vector<int>> graph;
bool visited[101] = {false};

void dfs(int num) {
  if (visited[num] == true)
    return;
  visited[num] = true;
  for (int i = 0; i < graph[num].size(); i++) {
    if (visited[graph[num][i]] == false) {
      cnt += 1;
      dfs(graph[num][i]);
    }
  }
}

void bfs() {
  queue<int> q;
  visited[1] = true;
  q.push(1);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < graph[now].size(); i++) {
      if (visited[graph[now][i]] == false) {
        cnt += 1;
        visited[graph[now][i]] = true;
        q.push(graph[now][i]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> m;
  graph.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }
//   dfs(1);
  bfs();
  cout << cnt << "\n";
}