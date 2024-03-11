#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  getline(cin, str);
  int cnt = 1;
  for (int i = 0; i < str.length(); i++) {
    if (i != 0 && i != (str.length() - 1) && str[i] == ' ')
      cnt ++;
  }
  if (str.length() == 1 && str[0] == ' ')
    cout << 0 << endl;
  else
      cout << cnt << endl;
  return 0;
}