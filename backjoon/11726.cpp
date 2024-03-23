#include <iostream>
#include <vector>
using namespace std;

vector<int> result;
int main() {
  int n;
  cin >> n;
  result.resize(n + 1);
  result[1] = 1;
  result[2] = 2;
  for (int i = 3; i <= n; i++) {
    result[i] = (result[i-1] + result[i-2])%10007;
  }
  cout << result[n] << endl;
}