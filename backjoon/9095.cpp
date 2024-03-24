#include <iostream>
#include <vector>
using namespace std;

vector<int> result;
int main() {
  int n;
  cin >> n;
  result.resize(11);
  result[1] = 1;
  result[2] = 2;
  result[3] = 4;
  for (int i = 4; i <= 10; i++) {
    result[i] = result[i-1] + result[i-2] + result[i-3];
  }
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    cout << result[in] << endl;
  }
}