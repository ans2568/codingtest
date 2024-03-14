#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int num) {
  if (num == 1)
    return false;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

vector<int> result;
int M, N;
int main() {
  cin >> M >> N;
  int min = N;
  for (int i = M; i <= N; i++) {
    if (isPrime(i)) {
      result.push_back(i);
      if (min > i)
        min = i;
    }
  }
  if (result.size() == 0)
    cout << -1 << endl;
  else {
    int sum = 0;
    for (auto &r : result)
      sum += r;
    cout << sum << endl;
    cout << min << endl;
  }
  return 0;
}