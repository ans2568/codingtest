#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int R, T;
vector<string> result;
int main() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> R >> s;
    string str = "";
    for (int j = 0; j < s.length(); j++) {
        for (int k = 0; k < R; k++) {
            str += s[j];
        }
    }
    result.push_back(str);
  }
  for (auto &r : result)
    cout << r << endl;
  return 0;
}