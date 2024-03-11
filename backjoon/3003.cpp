#include <iostream>
#include <vector>
using namespace std;
vector<int> piece = {1, 1, 2, 2, 2, 8};
vector<int> input(6, 0);
int main() {
  for (int i = 0; i < input.size(); i++) {
    cin >> input[i];
  }
  for (int i = 0; i < input.size(); i++) {
    piece[i] -= input[i];
  }
  for (auto p : piece)
    cout << p << " ";
  cout << endl;
  return 0;
}