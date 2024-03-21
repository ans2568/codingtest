#include <iostream>

using namespace std;

int N;
int main() {
  int x, y;
  cin >> N;
  int min_val = 1666;
  bool make = false;
  for (int x = 0; x < 1667; x++) {
    for (int y = 0; y <= 1000; y++) {
      if (3 * x + 5 * y == N) {
        make = true;
        int sum = x + y;
        if (sum < min_val)
          min_val = sum;
      }
    }
  }
  if (!make)
    cout << -1 << endl;
  else
    cout << min_val << endl;
}