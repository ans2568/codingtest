#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

int T, cent;
vector<vector<int>> result;
int main() {
  // 1 dollar = 100 cent
  cin >> T;
  int quater = 25, dime = 10, nickel = 5, penny=1;
  for (int i = 0; i < T; i++) {
    cin >> cent;
    int q_num=0, d_num=0, n_num=0, p_num=0;
    q_num = cent / quater;
    cent %= quater;
    if (cent > 0) {
        d_num = cent / dime;
        cent %= dime;
        if (cent > 0) {
          n_num = cent / nickel;
          cent %= nickel;
          if (cent > 0) {
            p_num = cent / penny;
          }
        }
    }
    vector<int> row = {q_num, d_num, n_num, p_num};
    result.push_back(row);
  }
  for (auto &res : result) {
    for (auto &r : res)
      cout << r << " ";
    cout << endl;
  }

  return 0;
}