#include <iostream>
#include <string>

using namespace std;
int alphabet[26] = {0};

int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); ++i) {
    int num = str[i] - 'a';
    alphabet[num]++;
  }
  for (int i = 0; i < 26; ++i) {
    cout << int(alphabet[i]) << " ";
  }
  cout << endl;
}