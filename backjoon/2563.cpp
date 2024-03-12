#include <iostream>

using namespace std;
int N;
int area[100][100] = {0};
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = x; j < x + 10; j++) {
      for (int k = y; k < y + 10; k++) {
        area[j][k] = 1;
      }
    }
  }
  int result = 0;
  for (int x = 0; x < 100; x++) {
    for (int y = 0; y < 100; y++) {
      result += area[x][y];
    }
  }
  cout << result << endl;

  return 0;
}