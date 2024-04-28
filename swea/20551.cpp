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
    int A, B, C, res = 0;
    bool success = false;
    cin >> A >> B >> C;
    if (B == 1 || C == 1) {
      success = true;
    }
    while (C <= B) {
      B--;
      res++;
    }
    while (B <= A) {
      A--;
      res++;
    }
    cout << "#" << test_case << " ";
    if (success)
      cout << -1 << "\n";
    else
      cout << res << "\n";
  }

  return 0;
}