#include <iostream>

using namespace std;

int N;

int main() {
  cin >> N;
  int cnt = 1, start_index = 1, end_index = 1, sum = 1;
  while (end_index != N) {
    if (sum == N) {
      cnt++;
      end_index++;
      sum = sum + end_index;
    } else if (sum > N) {
      sum -= start_index;
      start_index++;
    } else {
      end_index++;
      sum = sum + end_index;
    }
  }
  cout << cnt << endl;
  return 0;
}