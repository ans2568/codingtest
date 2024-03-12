#include <iostream>
#include <string>
using namespace std;

int main() {

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    string row = "";
    for (int j = i; j < N; j++) {
      row += " ";
    }
    for (int k = 0; k < i; k++) {
      row += "*";
    }
    for (int l = 0; l < i-1; l++) {
      row += "*";
    }
    cout << row << endl;
  }
  for (int i = 1; i < N; i++) {
    string row = "";
    for (int j = 0; j < i; j++) {
      row += " ";
    }
    for (int k = i; k < N; k++) {
      row += "*";
    }
    for (int l = i+1; l < N; l++) {
      row += "*";
    }
    cout << row << endl;
  }
}