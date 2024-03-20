#include <iostream>

using namespace std;

int main() {
  int a1, a0, c, n0;
  cin >> a1 >> a0 >> c >> n0;
  if (c  == a1) {
    if (a0 <= 0)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  } else {
    bool one = true;
    for (int n = n0; n < 100; n++) {
      if (!(a1 * n + a0 <= c * n))
        one = false;
    }
    if (one)
        cout << 1 << endl;
    else
        cout << 0 << endl;
  }
}