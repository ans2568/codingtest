#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> points;
int N;
char map[6][6];
bool see[6][6];
vector<points> teachers;
vector<points> students;
vector<points> empties;
bool safe;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int depth, int idx);

void checkArea() {
  for (int i = 0; i < teachers.size(); i++) {
    for (int j = 0; j < 4; j++) {
      int x = teachers[i].first;
      int y = teachers[i].second;
      see[x][y] = true;
      while (true) {
        x += dx[j];
        y += dy[j];
        if (x < 0 || y < 0 || x >= N || y >= N) // 맵 밖으로 안나가게 설정
          break;
        if (map[x][y] == 'O') // 선생이 장애물에 의해 막힘
          break;
        see[x][y] = true;
      }
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char c;
      cin >> c;
      map[i][j] = c;
      if (c == 'T')
        teachers.push_back({i, j});
      else if (c == 'S')
        students.push_back({i, j});
      else if (c == 'X')
        empties.push_back({i, j});
    }
  }
  dfs(0, 0);

  if (safe)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}

void dfs(int depth, int idx) {
  if (depth == 3) {
    memset(see, false, sizeof(see));
    checkArea();
    for (int i = 0; i < students.size(); i++) {
      int x = students[i].first;
      int y = students[i].second;
      if (see[x][y])
        return;
    }
    safe = true;
    return;
  }
  for (int i = idx; i < empties.size(); i++) {
    int x = empties[i].first;
    int y = empties[i].second;
    map[x][y] = 'O';
    dfs(depth + 1, i + 1);
    map[x][y] = 'X';
  }
}
