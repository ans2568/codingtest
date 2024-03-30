#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int graph[50][50];
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
int w, h, cnt;
bool visited[50][50];
queue<pair<int, int>> q;

void bfs(int a, int b) {
  q.push(make_pair(a, b));
  visited[a][b] = true;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if ((new_x >= 0 && new_x < h) && (new_y >= 0 && new_y < w)) {
        if (!visited[new_x][new_y] && graph[new_x][new_y]) {
          visited[new_x][new_y] = true;
          q.push(make_pair(new_x, new_y));
        }
      }
    }
  }
}

int main() {
  while (true) {
    cnt = 0;
    memset(visited, false, sizeof(visited));
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> graph[i][j];
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!visited[i][j] && graph[i][j]) {
          cnt++;
          bfs(i, j);
        }
      }
    }
    cout << cnt << "\n";
  }
}