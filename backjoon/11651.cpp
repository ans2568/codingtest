#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> xy;
bool compare(const xy &a, const xy &b) {
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

vector<xy> answer;
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    answer.push_back(make_pair(x, y));
  }
  sort(answer.begin(), answer.end(), compare);
  for (auto &ans : answer)
    cout << ans.first << " " << ans.second << "\n";
}