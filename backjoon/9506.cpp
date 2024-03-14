#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int n;
vector<pair<bool, vector<int>>> result;
int main() {
  while (true) {
    cin >> n;
    if (n == -1)
      break;
    vector<int> res;
    res.push_back(n);
    int sum = 0;
    for (int i = 1; i < n; i++) {
      if (n % i == 0) {
        sum += i;
        res.push_back(i);
      }
    }
    if (sum == n)
      result.push_back(make_pair(true, res));
    else
     result.push_back(make_pair(false, res));
  }
  for (auto &res : result) {
    if (res.first) {
      cout << res.second[0] << " = " << res.second[1];
      for (int i=2; i<res.second.size(); i++) {
        cout << " + " << res.second[i];
      }
      cout << endl;
    } else {
      cout << res.second[0] << " is NOT perfect." << endl; 
    }
  }
  return 0;
}