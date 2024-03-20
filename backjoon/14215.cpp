#include <iostream>

using namespace std;

int line[3];
int main() {
  int max_ = 0, sum = 0;
  for (int i = 0; i < 3; i++) {
    cin >> line[i];
    if (max_ < line[i])
      max_ = line[i];
    sum += line[i];
  }
  if ((sum - max_) <= max_)
    cout << (sum - max_) * 2 - 1 << endl;
  else
    cout << sum << endl;
}