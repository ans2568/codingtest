#include <iostream>
#include <string>
using namespace std;
int T, test_case;

int main(int argc, char **argv) {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    string A, B;
    cin >> A >> B;
    string res;
    if (A == B)
      res = A;
    else
      res = "1";

    cout << "#" << test_case << " " << res << "\n";
  }

  return 0;
}