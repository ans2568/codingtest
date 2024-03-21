#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> result;
  for (int i = 1; i < N; i++) {
    int sum = 0;
    string str = to_string(i);
    for (int j = 0; j < str.size(); j++) {
      int num = str[j] - '0';
      sum += num;
    }
    sum += i;
    if (sum == N)
      result.push_back(i);
  }
  if (result.size() == 0)
    cout << 0 << endl;
  else {
    int min = 1000000;
    for (auto &res : result) {
        if (min > res)
        min = res;
    }
    cout << min << endl;
  }
}