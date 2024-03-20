#include <iostream>
#include <math.h>
using namespace std;

int x, y, w, h;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> x >> y >> w >> h;
  int y_min = min(y, h - y);
  int x_min = min(x, w - x);
  int min_ = min(x_min, y_min);
  cout << min_ << endl;

  return 0;
}