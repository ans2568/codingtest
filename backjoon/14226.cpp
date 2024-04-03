#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<pair<int, int>, int> dct; // display, clipboard, time
int S;
int visited[1001][1001];

int bfs() {
  queue<dct> q; // {{바탕화면, 클립보드}, 시간}
  q.push(make_pair(make_pair(1, 0), 0));
  visited[1][0] = true;
  while (!q.empty()) {
    int display = q.front().first.first;
    int clipboard = q.front().first.second;
    int time = q.front().second;
    q.pop();
    if (display == S)
      return time;
    if (display > 0 && display <= 1000) {
      // 바탕화면 이모티콘 복사
      if (!visited[display][display]) {
        visited[display][display] = true;
        q.push(make_pair(make_pair(display, display), time + 1));
      }
      // 바탕화면 이모티콘 삭제
      if (!visited[display - 1][clipboard]) {
        visited[display - 1][clipboard] = true;
        q.push(make_pair(make_pair(display - 1, clipboard), time + 1));
      }
    }
    // 이모티콘 붙여넣기
    if (clipboard > 0 && display + clipboard <= 1000) {
      if (visited[display + clipboard][clipboard] == false) {
        visited[display + clipboard][clipboard] = true;
        q.push(make_pair(make_pair(display+clipboard, clipboard), time + 1));
      }
    }
  }
  return 0;
}

int main() {
  cin >> S;
  cout << bfs() << endl;
}