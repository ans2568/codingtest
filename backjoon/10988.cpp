#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string str, reverse_str;
int main() {
  cin >> str;
  reverse_str = str;
  reverse(reverse_str.begin(), reverse_str.end());
  if (str == reverse_str)
    cout << 1 << endl;
  else
    cout << 0 << endl;

  return 0;
}