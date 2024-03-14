#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  int cnt = 1;
  int end = 1;
  int d = 6;
  while (true) {
    if (N == 1)
      break;
    end += cnt * d;
    cnt++;
    if (N <= end) {
      break;
    }
  }
  cout << cnt << endl;
  return 0;
}
