#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> rows(5, "");
vector<vector<char>> result;
vector<vector<char>> res;
int main() {
  result.resize(5, vector<char>(15, ' '));
  res.resize(15, vector<char>(5, ' '));
  for (int i = 0; i < 5; i++) {
    cin >> rows[i];
    for (int j = 0; j < rows[i].length(); j++) {
      result[i][j] = rows[i][j];
    }
  }
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 5; j++) {
      res[i][j] = result[j][i];
    }
  }
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      if (res[i][j] == ' ')
        continue;
      else
        cout << res[i][j];
    }
  }
  cout << endl;
}