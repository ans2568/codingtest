#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
int R, C, endx, endy, ans = 0;
char graph[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
queue<pair<int, int>> rain;
bool visited[51][51], visited2[51][51];
int bfs() {
  while (!q.empty()) {
    int sz = rain.size();
    while (sz--) {
      int x = rain.front().first;
      int y = rain.front().second;
      rain.pop();
      for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x < 0 || new_x >= R || new_y < 0 || new_y >= C ||
            graph[new_x][new_y] == 'X' || graph[new_x][new_y] == 'H' ||
            visited2[new_x][new_y])
          continue;
        visited2[new_x][new_y] = true;
        rain.push(make_pair(new_x, new_y));
      }
    }

    sz = q.size();
    while (sz--) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      if (x == endx && y == endy) {
        return ans;
      }
      for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x < 0 || new_x >= R || new_y < 0 || new_y >= C ||
            graph[new_x][new_y] == 'X' || visited[new_x][new_y] ||
            visited2[new_x][new_y])
          continue;
        visited[new_x][new_y] = true;
        q.push(make_pair(new_x, new_y));
      }
    }
    ans++;
  }
  return -1;
}

int main(int argc, char **argv) {
  memset(visited, false, sizeof(visited));
  memset(visited2, false, sizeof(visited2));
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> graph[i][j];
      if (graph[i][j] == 'W') {
        visited[i][j] = true;
        q.push(make_pair(i, j));
      } else if (graph[i][j] == '*') {
        visited2[i][j] = true;
        rain.push(make_pair(i, j));
      } else if (graph[i][j] == 'H') {
        endx = i;
        endy = j;
      }
    }
  }
  if (bfs() != -1)
    cout << ans << endl;
  else
    cout << "FAIL" << endl;
  return 0;
}