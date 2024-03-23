#include <iostream>
#include <vector>
using namespace std;

vector<int> result;
int main() {
  int n;
  cin >> n;
  result.resize(n + 1);
  result[1] = 0;
  for (int i = 2; i <= n; i++) {
    result[i] = result[i - 1] + 1;
    if (i % 2 == 0)
      result[i] = min(result[i], result[i / 2] + 1);
    if (i % 3 == 0)
      result[i] = min(result[i], result[i / 3] + 1);
  }
  cout << result[n];
}