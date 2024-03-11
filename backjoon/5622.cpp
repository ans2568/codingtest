#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<pair<vector<char>, int>> vec = {
    {{'A', 'B', 'C'}, 2}, {{'D', 'E', 'F'}, 3}, {{'G', 'H', 'I'}, 4},
    {{'J', 'K', 'L'}, 5}, {{'M', 'N', 'O'}, 6}, {{'P', 'Q', 'R', 'S'}, 7},
    {{'T', 'U', 'V'}, 8}, {{'W', 'X', 'Y', 'Z'}, 9}
};
int main() {
  string str;
  cin >> str;
  int cost = 0;
  for (int i = 0; i < str.length(); i++) {
    bool isOper = true;
    for (auto v : vec) {
      for (auto a : v.first) {
          if (a == str[i]) {
            isOper = false;
            cost += v.second + 1;
          }
        }
    }
    if (isOper)
        cost += 11;
  }
  cout << cost << endl;

  return 0;
}