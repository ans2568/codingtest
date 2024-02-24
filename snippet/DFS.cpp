#include <vector>
#include <algorithm>

using namespace std;


void DFS(int x);            // 무방향 그래프(노드)
vector<vector<int>> node_graph;
vector<bool> visited;

bool DFS(int h, int w);     // WxH 로 나타내는 그리드 행렬
int W, H;                   // width, height
int graph[101][101];

void DFS(int x) {
  if (visited[x] == true)
    return;
  visited[x] = true;

  for (size_t i = 0; i < node_graph[x].size(); i++) {
    if (visited[node_graph[x][i]] == false) {
      DFS(node_graph[x][i]);
      // count += 1;        // 문제에 해당하는 노드 수 += 1
    }
  }
}

bool DFS(int h, int w) {
  if (h <= -1 || w <= -1 || h >= H || w>= W)
    return false;
  if (graph[h][w] == 0) {
    graph[h][w] = 1;
    DFS(h, w + 1);
    DFS(h, w - 1);
    DFS(h + 1, w);
    DFS(h - 1, w);
    return true;
  }
  return false;
}