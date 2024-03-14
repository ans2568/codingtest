#include <iostream>
#include <vector>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  if (N == 1)
    return 0;
  for (int i = 2; i <= N;) {
    if (N % i == 0) {
      N /= i;
      cout << i << "\n";
    } else
      i++;
  }
  return 0;
}