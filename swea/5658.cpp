#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int T, test_case;

string rotate(string str) {
  char temp;
  temp = str[0];
  string result;
  for (int i = 1; i < str.size(); ++i) {
    result += str[i];
  }
  result += temp;
  return result;
}

int main(int argc, char **argv) {
  // cin.tie(NULL);
  // cout.tie(NULL);
  // ios_base::sync_with_stdio(false);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int N, K;
    cin >> N >> K;
    int row = N / 4;
    vector<string> vec;
    string str, str_cpy;
    cin >> str;
    str_cpy = str;
    for (int n = 0; n < row; ++n) {
      for (int i = 0; i < str_cpy.size();) {
        int r = row;
        string s;
        while (r--) {
          s += str_cpy[i];
          i++;
        }
        vec.push_back(s);
      }
      str_cpy = rotate(str_cpy);
    }
    vector<int> result;
    for (auto &v : vec) {
      int num = (int)strtol(v.c_str(), NULL, 16);
      result.push_back(num);
    }
    sort(result.begin(), result.end(), greater<>());
    unique(result.begin(), result.end());
    cout << "#" << test_case << " ";
    cout << result[K - 1] << "\n";
  }

  return 0;
}