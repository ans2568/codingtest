#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct Point {
  int x;
  int y;
};
int t, store;
Point stores[100];
Point home;
Point festival;
bool visited[100];

bool bfs(int s) {
  queue<pair<int, int>> q;
  q.push(make_pair(home.x, home.y));
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (abs(festival.x - x) + abs(festival.y - y) <= 1000)
      return true;
    for (int i = 0; i < s; i++) {
      if (visited[i])
        continue;
      if (abs(stores[i].x - x) + abs(stores[i].y - y) <= 1000) {
        visited[i] = true;
        q.push(make_pair(stores[i].x, stores[i].y));
      }
    }
  }
  return false;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    memset(visited, false, sizeof(visited));
    cin >> store;
    cin >> home.x >> home.y;
    for (int j = 0; j < store; j++) {
      cin >> stores[j].x >> stores[j].y;
    }
    cin >> festival.x >> festival.y;

    if (bfs(store))
      cout << "happy" << "\n";
    else
      cout << "sad" <<"\n";
  }
  
}