#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> tall(9, 0);
int main() {
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    cin >> tall[i];
    sum += tall[i];
  }
  sort(tall.begin(), tall.end());
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (sum - (tall[i] + tall[j]) == 100) {
        for (int z = 0; z < 9; z++) {
          if (z != i && z != j) {
            cout << tall[z] << "\n";
          }
        }
        return 0;
      }
    }
  }
}