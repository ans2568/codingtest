#include <iostream>

using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int number[10001] = {0};
  for (int i = 0; i < N; i++) {
    int in;
    cin >> in;
    number[in] += 1;
  }
  for (int i = 0; i < 10001; i++) {
    for (int j = 0; j < number[i]; j++) {
      cout << i << "\n";
    }
  }
}