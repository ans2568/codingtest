#include <iostream>
#include <queue>
#include <cstring>
#define MAX_SIZE 301
using namespace std;
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int graph[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int L;
queue<pair<int, int>> q;

void bfs() {
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if ((new_x < 0 || new_x >= L) || (new_y <0 || new_y >= L)) continue;
      if (!visited[new_x][new_y]) {
        visited[new_x][new_y] = true;
        q.push(make_pair(new_x, new_y));
        dist[new_x][new_y] = dist[x][y] + 1;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    memset(dist, 0, sizeof(dist));
    memset(visited, false, sizeof(visited));
    cin >> L;
    int src_x, src_y, des_x, des_y;
    cin >> src_x >> src_y;
    q.push(make_pair(src_x, src_y));
    visited[src_x][src_y] = true;
    cin >> des_x >> des_y;
    bfs();
    cout << dist[des_x][des_y] << "\n";
  }
}