#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int n, cnt = 0;
int graph[25][25];
bool visited[25][25] = {false};
vector<int> result;

int bfs(int x, int y) {
  if (graph[x][y] == 0 || visited[x][y])
    return -1;
  cnt += 1;
  int house_count = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  visited[x][y] = true;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if ((0 <= new_x && new_x < n) && (0 <= new_y && new_y < n) && visited[new_x][new_y] == false && graph[new_x][new_y] == 1) {
        visited[new_x][new_y] = true;
        house_count += 1;
        q.push(make_pair(new_x, new_y));
      }
    }
  }
  return house_count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < str.size(); j++) {
      graph[i][j] = str[j] - '0';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int res = bfs(i, j);
      if (res != -1)
        result.push_back(res);
    }
  }
  cout << cnt << "\n";
  sort(result.begin(), result.end());
  for (auto &res : result)
    cout << res << "\n";
}