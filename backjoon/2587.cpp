#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> num(5, 0);
int main() {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    cin >> num[i];
    sum += num[i];
  }
  int avg = sum / 5;
  sort(num.begin(), num.end());
  cout << avg << endl;
  cout << num[2] << endl;
}