#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<int> cards(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> cards[i];
  }

  vector<int> vec;
  for (int i = 0; i < cards.size(); i++) {
    for (int j = i + 1; j < cards.size(); j++) {
      for (int k = j + 1; k < cards.size(); k++) {
        int sum = cards[i] + cards[j] + cards[k];
        vec.push_back(sum);
      }
    }
  }
  int sub = 300000;
  int result = 0;
  for (auto &v : vec) {
    if (0 <= (M - v) && (M - v) < sub) {
      sub = M - v;
      result = v;
    }
  }
  cout << result << endl;

}