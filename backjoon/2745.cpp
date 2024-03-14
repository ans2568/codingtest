#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;
string N;
int B;
int main() {
  cin >> N >> B;
  int result = 0;
  reverse(N.begin(), N.end());
  for (int i = 0; i < N.length(); i++) {
    if ('0' <= N[i] && N[i] <= '9')
      N[i] -= '0';
    else
      // ASCII A=65, ... , Z=90을 A=10, ... , Z=35 로 변환
      N[i] = N[i] + 10 - 'A';
    // 10진법으로 변환
    result += (N[i] * (pow(B, i)));
  }
  cout << result << endl;
    return 0;
}