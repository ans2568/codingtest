#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, h;
int tomato[101][101][101];
int dz[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};

int dist[101][101][101];
int day = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n >> h;
  queue<pair<pair<int, int>, int>> Q;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        cin >> tomato[i][j][k];
        if (tomato[i][j][k] == 1) {
          Q.push({{i, j}, k});
        }
        if (tomato[i][j][k] == 0)
          dist[i][j][k] = -1;
      }
    }
  }
  while (!Q.empty()) {
    pair<pair<int, int>, int> cur = Q.front();
    Q.pop();
    for (int i = 0; i < 6; i++) {
      int nz = cur.first.first + dz[i];
      int nx = cur.first.second + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 1 || nx > n || ny < 1 || ny > m || nz < 1 || nz > h)
        continue;
      if (dist[nz][nx][ny] >= 0)
        continue;
      dist[nz][nx][ny] =
          dist[cur.first.first][cur.first.second][cur.second] + 1;
      Q.push({{nz, nx}, ny});
    }
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        if (dist[i][j][k] == -1) {
          cout << -1;
          return 0;
        }
        day = max(day, dist[i][j][k]);
      }
    }
  }
  cout << day;
}