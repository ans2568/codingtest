#include <iostream>

using namespace std;

int n;
int main() {
  cin >> n;
  int x_min = 10000, y_min = 10000, x_max=-10000, y_max = -10000;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x_min > x)
      x_min = x;
    if (x_max < x)
      x_max = x;
    if (y_min > y)
      y_min = y;
    if (y_max < y)
      y_max = y;
  }
  cout << (x_max - x_min) * (y_max - y_min) << endl;

  return 0;
}
