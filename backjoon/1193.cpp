#include <iostream>
using namespace std;

int N;
int main() {
  cin >> N;
  int i = 1;
  int child, parent;
  while (N > i) {
    N -= i;
    i++;
  }
  if (i % 2 == 0)
    cout << N << '/' << i + 1 - N << endl;
  else
    cout << i + 1 - N << '/' << N << endl;
  return 0;
}