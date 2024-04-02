#include <iostream>
#include <vector>

using namespace std;
vector<int> limits;
vector<int> tests;
int N, M, d, v;
int main(int argc, char **argv) {
  cin >> N >> M;
  while (N--) {
    cin >> d >> v;
    for (int i = 0; i < d; i++)
      limits.push_back(v);
  }
  while (M--) {
    cin >> d >> v;
    for (int i = 0; i < d; i++)
      tests.push_back(v);
  }
  int max_val = 0;
  for (int i = 0; i < 100; i++) {
    max_val = max(max_val, tests[i] - limits[i]);
  }
  cout << max_val << endl;

  return 0;
}