#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, day = 0;
int map[1001][1001];
queue<pair<int, int>> q;

void bfs() {
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx <= 0 || ny <= 0 || nx > M || ny > N)
        continue;
      if (map[ny][nx] == 0) {
        map[ny][nx] = map[y][x] + 1;
        q.push(make_pair(ny, nx));
      }
    }
  }
}

int main() {
  freopen("../input.txt", "r", stdin);
  cin >> M >> N;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> map[i][j];
      if (map[i][j] == 1)
        q.push(make_pair(i, j));
    }
  }
  bfs();

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (map[i][j] == 0) {
        cout << -1 << endl;
        return 0;
      }
      if (day < map[i][j]) {
        day = map[i][j];
      }
    }
  }
  cout << day - 1 << endl;
  return 0;
}