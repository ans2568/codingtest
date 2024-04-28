#include <iostream>
#include <vector>
using namespace std;
int T, test_case;

int main(int argc, char **argv) {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    int N;
    long res = 0;
    cin >> N;
    vector<long> vec(N, 0);
    for (int i = 0; i < N; ++i) {
      cin >> vec[i];
    }
    long max = vec[N - 1];
    for (int i = vec.size() - 2; i >= 0; --i) {
      if (vec[i] < max) {
        res += max - vec[i];
      } else {
        max = vec[i];
      }
    }
    cout << "#" << test_case << " ";
    cout << res << "\n";
  }

  return 0;
}