// 최대 공약수
int gcd(int a, int b) {
  int c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

// 최소 공배수
int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}