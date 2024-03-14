#include <iostream>
#include <math.h>
using namespace std;

// 소수인지 판별
bool isPrime(int number) {
  if (number == 1) return false;
  for (int i = 2; i <= sqrt(number); i++) {
    if (number % i == 0)
      return false;
  }
  return true;
}

int N;
int main() {
  cin >> N;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (isPrime(num))
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}