#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N, M;
int graph[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int block[101][101];

void bfs() {
  queue<pair<int, int>> q;
  q.push(make_pair(1, 1));
  block[1][1] = 0;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx <= 0 || ny <= 0 || nx > M || ny > N)
        continue;
      if (graph[nx][ny]) {
        if (block[nx][ny] > block[x][y] + 1) {
          block[nx][ny] = block[x][y] + 1;
          q.push(make_pair(nx, ny));
        }
      } else {
        if (block[nx][ny] > block[x][y]) {
          block[nx][ny] = block[x][y];
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= N; j++) {
      block[i][j] = 987654321;
      graph[i][j] = str[j-1] - '0';
    }
  }
  bfs();
  cout << block[M][N] << endl;
}