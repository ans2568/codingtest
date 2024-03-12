#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string str;
vector<pair<int, char>> alphabet = {
    {0, 'a'},  {0, 'b'},  {0, 'c'},  {0, 'd'},  {0, 'e'},  {0, 'f'},  {0, 'g'},
    {0, 'h'},  {0, 'i'},  {0, 'j'}, {0, 'k'}, {0, 'l'}, {0, 'm'}, {0, 'n'},
    {0, 'o'}, {0, 'p'}, {0, 'q'}, {0, 'r'}, {0, 's'}, {0, 't'}, {0, 'u'},
    {0, 'v'}, {0, 'w'}, {0, 'x'}, {0, 'y'}, {0, 'z'}};

int main() {
  cin >> str;
  int max_ = 0;
  for_each(str.begin(), str.end(), [](auto &c) { c = tolower(c); });
  for (auto &c : str) {
    for (auto &a : alphabet) {
      if (c == a.second) {
        a.first += 1;
        if (max_ < a.first)
            max_ = a.first;
      }
    }
  }
  vector<char> result;
  for (auto &a : alphabet) {
    if (max_ == a.first) {
      char res = toupper(a.second);
      result.push_back(res);
    }
  }
  if (result.size() > 1)
    cout << "?" << endl;
  else
    cout << result[0] << endl;

  return 0;
}