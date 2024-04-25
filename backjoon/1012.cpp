#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[50][50];
bool visited[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int T, N, M, K;

void bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.push(make_pair(a, b));
  visited[a][b] = true;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx] || !map[ny][nx])
        continue;
      visited[ny][nx] = true;
      q.push(make_pair(ny, nx));
    }
  }
}

int main() {
  freopen("../input.txt", "r", stdin);
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    memset(map, 0, sizeof(map));
    cin >> M >> N >> K;
    for (int j = 0; j < K; ++j) {
      int x, y;
      cin >> x >> y;
      map[y][x] = 1;
    }
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (map[y][x] && !visited[y][x]) {
                bfs(y, x);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
  }

  return 0;
}