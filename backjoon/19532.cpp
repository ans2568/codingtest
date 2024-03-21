#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  for (int x = -999; x <= 999; x++) {
    for (int y = -999; y <= 999; y++) {
      if (a*x + b*y == c && d*x + e*y == f) {
        cout << x << " " << y << endl;
      }
    }
  }
}