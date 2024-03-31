#include <iostream>
#include <queue>
#include <string>
#include <utility>
#define MAX_SIZE 101
using namespace std;

int N, M;
int graph[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[MAX_SIZE][MAX_SIZE] = {false, };

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
      if ((new_x <= 0 || new_x > N) || (new_y <=0 || new_y > M)) continue;
      if (graph[new_x][new_y] && !visited[new_x][new_y]) {
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
    string row;
    cin >> row;
    for (int j = 1; j <= M; j++) {
      graph[i][j] = row[j-1] - '0';
    }
  }
  bfs();
  cout << dist[N][M] << "\n";
}