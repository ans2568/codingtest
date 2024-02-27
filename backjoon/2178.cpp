#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
int N, M;
int graph[101][101];
void bfs();
queue<pair<int, int>> queue_;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<bool>> visited;
vector<vector<int>> dist;

int main() {
  cin >> N >> M;
  visited.resize(N + 1, vector<bool>(M + 1, false));
  dist.resize(N+1, vector<int>(M+1));
  for (int i = 1; i <= N; i++) {
    string num;
    cin >> num;
    for (int j = 1; j <= M; j++) {
      int one = num[j - 1] - '0';
      if (one) {
        graph[i][j] = one;
      }
    }
  }
  bfs();
  cout << dist[N][M] << endl;
  return 0;
}

void bfs() {
  dist[1][1] = 1;
  visited[1][1] = true;
  queue_.push(make_pair(1, 1));
  while (!queue_.empty()) {
    auto now = queue_.front();
    queue_.pop();
    for (int i = 0; i < 4; i++) {
      if (now.first + dx[i] >= 1 && now.second + dy[i] >= 1 &&
          now.first + dx[i] <= N && now.second + dy[i] <= M) {
        if (graph[now.first + dx[i]][now.second + dy[i]] &&
            !visited[now.first + dx[i]][now.second + dy[i]]) {
          visited[now.first + dx[i]][now.second + dy[i]] = true;
          queue_.push(make_pair(now.first + dx[i], now.second + dy[i]));
          dist[now.first + dx[i]][now.second + dy[i]] = dist[now.first][now.second] + 1;
        }
      }
    }
  }
}