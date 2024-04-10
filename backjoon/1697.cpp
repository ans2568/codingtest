#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 100001
int N, K, res = 987654321;
int dx[] = {1, -1, 2};
bool visited[MAX_SIZE];

void bfs() {
  queue<pair<int, int>> q;
  q.push(make_pair(N, 0));
  visited[N] = true;
  while (!q.empty()) {
    int now = q.front().first;
    int time = q.front().second;
    q.pop();
    if (now == K) {
      res = min(res, time);
    }
    for (int i = 0; i < 3; ++i) {
      int nnow;
      if (dx[i] == 2)
        nnow = now*dx[i];
      else
        nnow = now + dx[i];
      if (nnow < 0 || nnow >= MAX_SIZE)
        continue;;
      if (visited[nnow])
        continue;;
      visited[nnow] = true;
      q.push(make_pair(nnow, time+1));
    }
  }
}

int main() {
  cin >> N >> K;
  bfs();
  cout << res << endl;
}