#include <iostream>
#include <string>
using namespace std;
int N, M, sx, sy;
char graph[51][51];
bool visited[51][51];
bool success = false;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int depth) {
  if ((x == sx && y == sy && depth >= 4) || success) {
    success = true;
    return;
  }
  if (visited[x][y])
    return;
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
      continue;
    if (graph[x][y] == graph[new_x][new_y]) {
      dfs(new_x, new_y, depth + 1);
    }
  }
  visited[x][y] = false;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < M; j++)
      graph[i][j] = str[j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j])
        continue;
      sx = i;
      sy = j;
      dfs(i, j, 0);
    }
  }
  if (success)
    cout << "Yes" << "\n";
  else
    cout << "No" << "\n";
}