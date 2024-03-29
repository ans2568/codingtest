#include <iostream>
using namespace std;

int main() {
  int n, result = 1;
  cin >> n;
  for (int i = n; i > 0; i--)
    result *= i;
  cout << result << endl;
}