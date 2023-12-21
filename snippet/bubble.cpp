#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N = 1000;
  vector<int> A(N, 0);
  bool change = false;
  for (int i = 1; i <= N + 1; i++) {
    change = false;
    for (int j = 1; j <= N - i; j++) {
      if (A.at(j) > A.at(j + 1)) { // 오름차순
        change = true;
        swap(A.at(j), A.at(j + 1));
      }
    }
    if (!change) // 더 이상 swap이 일어나지 않으면 종료
      break;
  }
  return 0;
}