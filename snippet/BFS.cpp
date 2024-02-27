#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void BFS(int x); // 무방향 그래프(노드)
vector<vector<int>> node_graph;
vector<bool> visited;

void BFS(int x, int y); // WxH 로 나타내는 그리드 행렬
int W, H;               // width, height
int dist[101][101];     // distance
int graph[101][101];
vector<vector<bool>> isVisited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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

void BFS(int x, int y) {
  dist[x][y] = 1;
  queue<pair<int, int>> queue;
  queue.push(make_pair(x, y));
  while (!queue.empty()) {
    int now_x = queue.front().first;
    int now_y = queue.front().second;
    queue.pop();
    for (int i = 0; i < 4; i++) {
      int nx = now_x + dx[i];
      int ny = now_y + dy[i];
      if (nx >= 1 && ny >= 1 && nx <= W && ny <= H) {
        if (graph[nx][ny] == 1 && !isVisited[nx][ny]) {
          isVisited[nx][ny] = true;
          queue.push(make_pair(nx, ny));
          dist[nx][ny] = dist[now_x][now_y] + 1;
        }
      }
    }
  }
}