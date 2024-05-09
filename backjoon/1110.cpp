#include <iostream>
using namespace std;
int N, result = 0, cnt = 0;

void foo(int & num) {
  if (num < 10)
    num = num*10 + num;
  else {
    int ten = num / 10;
    int one = num % 10;
    int sum = ten + one;
    num = one * 10 + sum % 10;
  }
  cnt++;
}

int main() {
  cin >> N;
  result = N;
  foo(result);
  while (result != N) {
    foo(result);
  }
  cout << cnt << endl;
  return 0;
}