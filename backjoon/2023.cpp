#include <iostream>
#include <math.h>

void DFS(int num, int a);
bool isPrime(int num);
static int N;

int main() {
  std::cin >> N;
  DFS(2, 1); // 소수, 해당 소수의 자릿수
  DFS(3, 1);
  DFS(5, 1);
  DFS(7, 1);
  return 0;
}

void DFS(int num, int a) {
  if (a == N) {
    // 소수 이면 출력
    if (isPrime(num)) {
      std::cout << num << std::endl;
    }
    return;
  }
  for (int i = 1; i < 10; i++) {
    if (i % 2 == 0)
      continue;
    if (isPrime(num * 10 + i)) {
      DFS(num * 10 + i, a + 1);
    }
  }
}

bool isPrime(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    // i가 제곱근까지 iterative하게 나눴을 때 약수이므로 소수가 아니게 됨
    if (num % 2 == 0)
      return false;
  }
  return true;
}