#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> scores;
int main() {
  int N, k;
  cin >> N >> k;
  scores.resize(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> scores[i];
  }
  sort(scores.begin(), scores.end(), greater<>());
  cout << scores[k-1] << endl;
}