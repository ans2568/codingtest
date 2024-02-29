#include <iostream>
#include <string>
using namespace std;

int first, second;
int result[4];
int main() {
  cin >> first >> second;
  string str = to_string(second);
  result[0] = first * (str[2] - '0');
  result[1] = first * (str[1] - '0');
  result[2] = first * (str[0] - '0');
  result[3] = first * second;

  for (auto &r : result)
    cout << r << endl;
  return 0;
}