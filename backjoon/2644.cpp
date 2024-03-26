#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, person, person2, m;
vector<vector<int>> graph;
bool visited[101];
int dist[101] = {0};

void bfs(int num) {
  queue<int> q;
  q.push(num);
  visited[num] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < graph[now].size(); i++) {
      if (visited[graph[now][i]] == false) {
        visited[graph[now][i]] = true;
        q.push(graph[now][i]);
        dist[graph[now][i]] = dist[now] + 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> person >> person2;
  cin >> m;
  graph.resize(n+1);
  for (int i = 0; i < m; i++) {
    int parent, child;
    cin >> parent >> child;
    graph[parent].push_back(child);
    graph[child].push_back(parent);
  }
  bfs(person);
  if (dist[person2] == 0)
    cout << -1 << "\n";
  else
    cout << dist[person2] << "\n";
}