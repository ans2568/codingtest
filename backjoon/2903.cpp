#include <iostream>
#include <math.h>

using namespace std;
int main() {
  int N;
  cin >> N;
  int start = 2, result = 0;
  for (int i = 1; i <= N; i++) {
    start += (start - 1);
    result = pow(start, 2);
  }
  cout << result << endl;
  return 0;
}