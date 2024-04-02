#include <cstring>
#include <iostream>

using namespace std;
int N, cnt;
int graph[100][100];
bool visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int h) {
  if (visited[x][y])
    return;
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= N || ny < 0 || ny >= N || graph[nx][ny] <= h ||
        visited[nx][ny])
      continue;
    dfs(nx, ny, h);
  }
}

int main() {
  cin >> N;
  int h = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> graph[i][j];
      h = max(h, graph[i][j]);
    }
  }
  int max_val = 0;
  for (int k = h; k >= 0; k--) {
    memset(visited, false, sizeof(visited));
    cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j] && graph[i][j] > k) {
          dfs(i, j, k);
          cnt++;
        }
      }
    }
    max_val = max(max_val, cnt);
  }
  cout << max_val << endl;
}