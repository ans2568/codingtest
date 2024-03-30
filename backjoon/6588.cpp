#include <cmath>
#include <iostream>
#define MAX_SIZE 1000000
using namespace std;
bool isPrime[MAX_SIZE];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int input, i, j;
  bool success = true;

  isPrime[0] = true;
  isPrime[1] = true;

  for (int i = 2; i <= sqrt(MAX_SIZE); i++) {
    if (isPrime[i] == false) {
      for (int j = i * i; j <= MAX_SIZE; j += i)
        isPrime[j] = true;
    }
  }
  while (true) {
    cin >> input;
    if (input == 0)
      break;

    for (i = 3; i <= input / 2; i += 2) {
      j = input - i;

      if (!isPrime[i] && !isPrime[j]) {
        cout << input << " = " << i << " + " << j << "\n";
        success = false;
        break;
      }
    }
    if (success == true)
      cout << "Goldbach's conjecture is wrong." << "\n";
  }
}