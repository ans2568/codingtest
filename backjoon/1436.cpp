#include <iostream>
#include <string>
using namespace std;

int main() {
  int i = 666;
  int series = 0;
  int n;
  cin >> n;
  string target;
  while (true) {
    target = to_string(i);
    for (int j = 2; j < target.length(); j++) {
      if (target[j - 2] == '6' && target[j - 1] == '6' && target[j] == '6') {
        series++;
        if (series == n) {
          cout << i << endl;
          return 0;
        }
        break;
      }
    }
    i++;
  }
}