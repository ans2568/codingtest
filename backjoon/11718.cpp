#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> result;
int main() {
  while (!cin.eof()) {
    string str;
    getline(cin, str);
    result.push_back(str);
  }

  for (auto &r : result)
    cout << r << endl;
  return 0;
}