#include <queue>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int, int> point;
typedef pair<int, point> ipt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mat[1001][1001];
int N, K, S, X, Y;
void bfs();
struct cmp {
  bool operator() (ipt a, ipt b) {
    if (a.first != b.first)
      return a.first > b.first;
    else
      return mat[a.second.first][a.second.second] > mat[b.second.first][b.second.second];
  }
};
priority_queue<ipt, vector<ipt>, cmp> pq;

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int v;
      cin >> v;
      mat[i][j] = v;
      if (v != 0) {
        pq.push(make_pair(1, make_pair(i, j)));
      }
    }
  }
  cin >> S >> X >> Y;
  bfs();
  cout << mat[X][Y];
  return 0;
}

void bfs() {
  while (!pq.empty()) {
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    int s = pq.top().first;
    pq.pop();
    if (s == S + 1)
      break;
    for (int i = 0; i < 4; i++) {
      if (x + dx[i] >= 1 && y + dy[i] >= 1 && x + dx[i] <= N &&
          y + dy[i] <= N) {
        if (!mat[x + dx[i]][y + dy[i]]) {
          mat[x + dx[i]][y + dy[i]] = mat[x][y];
          pq.push(make_pair(s + 1, make_pair(x + dx[i], y + dy[i])));
        }
      }
    }
  }
}