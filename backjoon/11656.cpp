#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> result;
int main() {
  string str, words = "";
  cin >> str;
  for (int i = str.size() - 1; i >= 0; i--) {
    string temp;
    words += str[i];
    temp = words;
    reverse(temp.begin(), temp.end());
    result.push_back(temp);
  }
  sort(result.begin(), result.end());
  for (auto &res : result)
    cout << res << "\n";
}