#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void BFS(int x); // 무방향 그래프(노드)
vector<vector<int>> node_graph;
vector<bool> visited;


void BFS(int x) {
  queue<int> queue;
  queue.push(x);
  visited[x] = true;

  while (!queue.empty()) {
    int now = queue.front();
    queue.pop();
    for (int i = 0; i < node_graph[now].size(); i++) {
      if (visited[node_graph[now][i]] == false) {
        visited[node_graph[now][i]] = true;
        queue.push(node_graph[now][i]);
      }
    }
  }
}