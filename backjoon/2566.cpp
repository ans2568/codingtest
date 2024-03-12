#include <iostream>

using namespace std;
int graph[10][10] = {0};
int main() {
  pair<int, pair<int, int>> result;
  int max_ = -1;
  result.first = max_;
  result.second.first = -1;
  result.second.second = -1;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cin >> graph[i][j];
      if (max_ < graph[i][j]) {
        max_ = graph[i][j];
        result.first = max_;
        result.second.first = i;
        result.second.second = j;
      }
    }
  }
  cout << result.first << endl;
  cout << result.second.first << " " << result.second.second << endl;
  

  return 0;
}