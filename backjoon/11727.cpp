#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> result(n + 1);
  result[1] = 1;
  result[2] = 3;
  for (int i = 3; i <= n; i++) {
    result[i] = (result[i-1] + 2*result[i-2])%10007;
  }
  cout << result[n] << endl;
}