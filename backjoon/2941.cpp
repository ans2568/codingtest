#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<string, int>> alphabet = {
    {"c=", 0}, {"c-", 0}, {"dz=", 0}, {"d-", 0},
    {"lj", 0}, {"nj", 0}, {"s=", 0},  {"z=", 0},
};

int main() {
  string str;
  cin >> str;
  int cnt = 0;
  for (int i = 0; i < alphabet.size(); i++) {
    while (true) {
    int idx = str.find(alphabet[i].first);
    if (idx != string::npos) {
      str.replace(idx, alphabet[i].first.length(), "|");
      cnt ++;
    } else break;
    }
  }
  while (true) {
    if (str.find("|") != string::npos)
        str.replace(str.find("|"), 1, "");
    else
     break;
  }
  cout << cnt + str.length() << endl;

  return 0;
}