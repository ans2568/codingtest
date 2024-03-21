#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> xy;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  // 첫 번째 원소가 같다면
  if (a.first == b.first)
    // 두 번째 원소 오름차순 정렬(1 2 3 4 5)
    return a.second < b.second;
  // 첫 번째 원소 오름차순 정렬
  return a.first < b.first;
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