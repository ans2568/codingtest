#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int alphabet[26];
bool visited[26];
int main() {
  string str;
  cin >> str;
  memset(alphabet, -1, sizeof(alphabet));
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < str.size(); ++i) {
    int idx = str[i] - 'a';
    if (visited[idx] == true) continue;
    alphabet[idx] = i;
    visited[idx] = true;
  }
  for (int i = 0; i < 26; ++i) {
    cout << alphabet[i] << " ";
  }
  cout << endl;
}