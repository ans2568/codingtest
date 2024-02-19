#include <math.h>

// 소수인지 판별
bool isPrime(int number) {
  for (int i = 2; i <= sqrt(number); i++) {
    if (number % i == 0)
      return false;
  }
  return true;
}