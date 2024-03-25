#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
int graph[101][101];
bool visited[101][101] = {false};
int dist[101][101];

void bfs() {
  queue<pair<int, int>> q;
  q.push(make_pair(1, 1));
  dist[1][1] = 1;
  visited[1][1] = true;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if ((1 <= new_x && new_x <= N) && (1 <= new_y && new_y <= M) &&
          visited[new_x][new_y] == false && graph[new_x][new_y] == 1) {
        visited[new_x][new_y] = true;
        q.push(make_pair(new_x, new_y));
        dist[new_x][new_y] = dist[x][y] + 1;
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < str.size(); j++) {
      graph[i][j + 1] = str[j] - '0';
    }
  }
  bfs();
  cout << dist[N][M] << endl;
}