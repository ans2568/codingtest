#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> x;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  x.resize(N);
  for (int i = 0; i < N; i++) {
    int first;
    cin >> first;
    x[i] = first;
  }
  vector<int> tmp(x);
  sort(tmp.begin(), tmp.end());
  auto it = unique(tmp.begin(), tmp.end());
  tmp.erase(it, tmp.end());
  for (int i = 0; i < N; i++) {
    auto iter = lower_bound(tmp.begin(), tmp.end(), x[i]);
    cout << iter - tmp.begin() << " ";
  }
  cout << "\n";
}