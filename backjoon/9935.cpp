#include <iostream>
#include <string>
using namespace std;

string input, ex, res;
void explode(string str) {
  for (int i = 0; i < input.size(); ++i) {
    res += input[i];
    if (res.size() >= ex.size()) {
      string s;
      s = res.substr(res.size() - ex.size(), ex.size());
      if (s == ex)
        res.erase(res.size() - ex.size(), ex.size());
    }
  }
  if (res.empty())
    res = "FRULA";
}

int main() {
  cout.tie(NULL);
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> input;
  cin >> ex;
  explode(ex);
  cout << res << "\n";
  return 0;
}