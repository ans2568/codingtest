#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> result;
int main() {
  while (true) {
    int s, e;
    bool neither = true;
    cin >> s >> e;
    if (s == 0 && e == 0)
      break;
    if (s > e) {
      if (s % e == 0) {
        neither = false;
        result.push_back("multiple");
      }
    } else if (s < e) {
      if (e % s == 0) {
        neither = false;
        result.push_back("factor");
      }
    }
    if (neither)
      result.push_back("neither");
  }
  for (auto res : result)
    cout << res << endl;

  return 0;
}