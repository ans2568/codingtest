#include <iostream>
using namespace std;

int A, B, C;
int result[4];

int main() {
  cin >> A >> B >> C;
  result[0] = (A + B) % C;
  result[1] = ((A % C) + (B % C)) % C;
  result[2] = (A * B) % C;
  result[3] = ((A % C) * (B % C)) % C;

  for (auto &r : result)
    cout << r << endl;
  return 0;
}