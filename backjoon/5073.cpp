#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> result;
int main() {
  while (true) {
    vector<int> line(3, 0);
    vector<bool> visited(1001, false);
    vector<int> cnt(1001, 0);
    int max = 0;
    for (int i = 0; i < 3; i++) {
      cin >> line[i];
      if (max < line[i])
        max = line[i];
      visited[line[i]] = true;
      cnt[line[i]] ++;
    }
    if (max == 0)
      break;
    int max_c = 0;
    for (int i=0; i<cnt.size(); i++) {
      if (cnt[i] > max_c) {
        max_c = cnt[i];
      }
    }
    int sum=0;
    for (auto &l : line)
      sum += l;

    if ((sum - max) <= max)
      result.push_back("Invalid");
    else if (max_c == 3)
      result.push_back("Equilateral");
    else if (max_c == 2)
      result.push_back("Isosceles");
    else
      result.push_back("Scalene");
  }
  for (auto &r : result)
    cout << r << endl;
}