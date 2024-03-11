#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> str;
int N;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s, res;
    cin >> s;
    res = s[0];
    res += s[s.length() - 1];
    str.push_back(res);
  }
  for (auto& s : str)
    cout << s << endl;

  return 0;
}