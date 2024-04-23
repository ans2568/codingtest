#include <iostream>
#include <stdexcept>
#include <unordered_map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N;
  unordered_map<int, int> um;
  for (int i = 1; i <= N; ++i) {
    int e;
    cin >> e;
    um.insert({e, 1});
  }
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int e;
    cin >> e;
    try {
      if (um.at(e)) {
        cout << um.at(e) << "\n";
      }
    } catch (out_of_range) {
        cout << "0" << "\n";
    }
  }
  return 0;
}