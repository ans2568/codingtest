#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<string, int> si;
bool compare(const si& a, const si& b) {
  if (a.second == b.second) {
    for (int i = 0; i < a.second; i++) {
      if (a.first[i] == b.first[i])
        continue;
      return a.first[i] < b.first[i];
    }
  }
  return a.second < b.second;
}

vector<si> answer;
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string in;
    cin >> in;
    answer.push_back(make_pair(in, in.size()));
  }
  sort(answer.begin(), answer.end(), compare);
  auto it = unique(answer.begin(), answer.end());
  answer.erase(it, answer.end());
  for (auto &ans : answer)
    cout << ans.first << "\n";
}