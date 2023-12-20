#include <vector>

using namespace std;

int main() {
  int N = 2000;
  vector<int> A(N, 0);

  // two pointer algorithm
  int count = 0;
  for (int k = 0; k < N; k++) {
    long find = A.at(k);
    int i = 0;     // start
    int j = N - 1; // end

    while (i < j) {
      if (A.at(i) + A.at(j) == find) {
        if (i != k && j != k) {
          count++;
          break;
        } else if (i == k) {
          i++;
        } else if (j == k) {
          j--;
        }
      } else if (A.at(i) + A.at(j) < find) {
        i++;
      } else if (A.at(i) + A.at(j) > find) {
        j--;
      }
    }
  }
  return 0;
}