#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100001
int N, K, res = 987654321;
int dx[] = {1, -1, 2};
bool visited[MAX_SIZE];
int parent[MAX_SIZE];
vector<int> result;
void bfs() {
  queue<pair<int, int>> q;
  vector<int> r;
  r.push_back(N);
  q.push(make_pair(N, 0));
  visited[N] = true;
  while (!q.empty()) {
    int now = q.front().first;
    int time = q.front().second;
    q.pop();
    if (now == K) {
      int idx = now;
      while (idx != N) {
        result.push_back(idx);
        idx = parent[idx];
      }
      result.push_back(N);
      reverse(result.begin(), result.end());
      res = min(res, time);
    }
    for (int i = 0; i < 3; ++i) {
      int nnow;
      if (dx[i] == 2)
        nnow = now * dx[i];
      else
        nnow = now + dx[i];
      if (nnow < 0 || nnow >= MAX_SIZE)
        continue;
      if (visited[nnow])
        continue;
      parent[nnow] = now;
      visited[nnow] = true;
      q.push(make_pair(nnow, time + 1));
    }
  }
}

int main() {
  cin >> N >> K;
  bfs();
  cout << res << endl;
  for (auto &r : result)
    cout << r << " ";
  cout << endl;
}