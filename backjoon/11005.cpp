#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;
int N, B;

int main() {
  cin >> N >> B;
  // A=65, Z=90
  string str = "";
  while (N != 0) {
      int tmp = N % B;
      if (tmp > 9) {
        tmp = tmp - 10 + 'A';
        str+=tmp;
      } else {
        str += ('0' + tmp);
      }
      N /= B;
  }
  reverse(str.begin(), str.end());
  cout << str << endl;
  return 0;
}