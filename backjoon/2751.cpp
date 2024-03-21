#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> number;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  number.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> number[i];
  }
  sort(number.begin(), number.end());
  for (auto &n : number)
    cout << n << "\n";
}