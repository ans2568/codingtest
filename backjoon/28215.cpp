#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int K, N;
vector<pair<int, int>> vec;

int dist(int p1, int p2, int p3) {
  int d = 0;
  for (int i = 0; i < N; ++i) {
    int x = vec[i].first;
    int y = vec[i].second;
    d = max(d, min({abs(vec[p1].first - x) + abs(vec[p1].second - y),
                    abs(vec[p2].first - x) + abs(vec[p2].second - y),
                    abs(vec[p3].first - x) + abs(vec[p3].second - y)}));
  }
  return d;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    vec.push_back(make_pair(x, y));
  }
  int res = 1e9;
  if (K == 1) {
    for (int i = 0; i < N; ++i)
      res = min(res, dist(i, i, i));
  } else if (K == 2) {
    for (int i = 0; i < N; ++i) {
      for (int j = i; j < N; ++j) {
        res = min(res, dist(i, i, j));
      }
    }
  } else if (K == 3) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          res = min(res, dist(i, j, k));
        }
      }
    }
  }
  cout << res << "\n";
  return 0;
}