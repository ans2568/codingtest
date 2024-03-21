#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string str;
  cin >> str;
  vector<int> num;
  for (int i = 0; i < str.size(); i++) {
    int n = str[i] - '0';
    num.push_back(n);
  }
  sort(num.begin(), num.end(), greater<>());
  string result = "";
  for (auto &n : num)
    result += char(n + '0');

  cout << result << endl;
}