#include <iostream>
#include <math.h>
using namespace std;

int DP[16];
int N;
int main(int argc, char **argv) {
  cin >> N;
  DP[1] = 9;
  DP[2] = 25;
  for (int i = 3; i <= N; i++) {
    DP[i] = pow(sqrt(DP[i - 1]) + pow(2, i - 1), 2);
  }
  cout << DP[N] << endl;

  return 0;
}