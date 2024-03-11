#include <iostream>
#include <string>

using namespace std;
string str;
int main() {
  int N, sum = 0;
  cin >> N;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    sum += str[i] - '0';
  }
  cout << sum << endl;
  return 0;
}