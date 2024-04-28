#include <iostream>
#include <vector>
using namespace std;
int T;

int main(int argc, char **argv) {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int sum = 0;
    vector<int> vec(10, 0);
    for (int j = 0; j < vec.size(); ++j) {
      cin >> vec[j];
      if (vec[j] % 2 == 1) {
        sum += vec[j];
      }
    }
    cout << "#" << i + 1 << " " << sum << "\n";
  }

  return 0;
}