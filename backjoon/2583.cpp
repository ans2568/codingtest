#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool DFS(int x, int y, int &area);

int M, N, K;
int graph[101][101];
vector<int> ans;

int main() {
  cin >> M >> N >> K;
  for (int i = 0; i < K; i++) {
    int x_0, x_1, y_0, y_1;
    cin >> x_0 >> y_0 >> x_1 >> y_1;
    for (int y = y_0; y < y_1; y++) {
      for (int x = x_0; x < x_1; x++) {
        graph[y][x] = 1;
      }
    }
  }
  int count = 0;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      int area = 0;
      if (DFS(j, i, area) == true) {
        count++;
        ans.push_back(area);
      }
    }
  }
  cout << count << endl;
  sort(ans.begin(), ans.end());
  for (auto &answer : ans)
    cout << answer << " ";
  cout << endl;

  return 0;
}

bool DFS(int x, int y, int &area) {
  if (x <= -1 || y <= -1 || x >= N || y >= M)
    return false;
  if (graph[y][x] == 0) {
    graph[y][x] = 1;
    area += 1;
    DFS(x + 1, y, area);
    DFS(x, y + 1, area);
    DFS(x - 1, y, area);
    DFS(x, y - 1, area);
    return true;
  }
  return false;
}