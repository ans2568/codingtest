#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M;
  cin >> N;
  cin >> M;
  vector<int> cloth(N, 0);
  for (int i = 0; i < N; i++)
    cin >> cloth[i];

  sort(cloth.begin(), cloth.end());
  int count = 0;
  int i = 0;
  int j = N - 1;
  while (i < j) {
      if (cloth[i] + cloth[j] > M) {
        j--;
      } else if (cloth[i] + cloth[j] < M) {
        i++;
      } else {
        count++;
        i++;
        j--;
      }
  }
  cout << count << endl;

  return 0;
}