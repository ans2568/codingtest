#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string A, B;
int main() {
  cin >> A >> B;
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  int new_a, new_b;
  new_a = stoi(A);
  new_b = stoi(B);
  cout << max(new_a, new_b) << endl;
  return 0;
}