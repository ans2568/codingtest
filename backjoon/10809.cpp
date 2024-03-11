#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<pair<int, char>> alphabet = {
    {1, 'a'}, {2, 'b'}, {3, 'c'},  {4, 'd'},  {5, 'e'},  {6, 'f'},  {7, 'g'},
    {8, 'h'}, {9, 'i'}, {10, 'j'}, {11, 'k'}, {12, 'l'}, {13, 'm'}, {14, 'n'},
    {15, 'o'}, {16, 'p'}, {17, 'q'}, {18, 'r'}, {19, 's'}, {20, 't'}, {21, 'u'},
    {22, 'v'}, {23, 'w'}, {24, 'x'}, {25, 'y'}, {26, 'z'}};
vector<int> idx(26, -1);

int main() {
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    for (auto c : alphabet) {
        if (str[i] == c.second && idx[c.first - 1] == -1)
          idx[c.first - 1] = i;
    }
  }
  for (auto i : idx)
    cout << i << " ";
  cout << endl;
  return 0;
}