#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> split(string str, char del) {
  istringstream ss(str);
  string buffer;
  vector<string> result;
  while (getline(ss, buffer, del)) {
    result.push_back(buffer);
  }
  return result;
}

int n;
vector<vector<string>> result;
int main() {
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin, str);
    auto res = split(str, ' ');
    result.push_back(res);
  }
  for (auto &res : result) {
    for (auto &r : res) {
      reverse(r.begin(), r.end());
    }
  }
  for (auto &res : result) {
    for (auto &r : res) {
      cout << r << " ";
    }
    cout << endl;
  }
}