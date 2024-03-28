#include <cmath>
#include <iostream>
#include <string>
using namespace std;

long long solution(string number, int size) {
  long long sum = 0;
  for (int i = 0; i < number.size(); i++) {
    long long num = number[i] - '0';
    num *= pow(10, size);
    size -= 1;
    sum += num;
  }
  return sum;
}

int main() {
  string a, b, c, d, a_b, c_d;
  cin >> a >> b >> c >> d;
  a_b = a + b;
  c_d = c + d;
  long long a_b_num = solution(a_b, a_b.size() - 1);
  long long c_d_num = solution(c_d, c_d.size() - 1);
  cout << a_b_num + c_d_num << "\n";
}