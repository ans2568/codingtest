#include <iostream>
using namespace std;

int angle[3];
bool visited[180] = {false};
bool Equilateral = false, Isosceles = false, Scalene = true;
int main() {
  int sum=0;
  for (int i = 0; i < 3; i++) {
    cin >> angle[i];
    sum += angle[i];
    if (visited[angle[i]]) {
      if (angle[i] == 60) {
        Equilateral = true;
        Scalene = false;
      } else {
        Isosceles = true;
        Scalene = false;
      }
    }
    visited[angle[i]] = true;
  }

  if (sum != 180) {
    cout << "Error" << endl;
  } else if (Scalene) {
    cout << "Scalene" << endl;
  } else if (Isosceles) {
    cout << "Isosceles" << endl;
  } else if (Equilateral) {
    cout << "Equilateral" << endl;
  }

}