#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  string str;
  cin >> str;
  list<char> li(str.begin(), str.end());
  auto cursor = li.end();
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    char command, alphabet;
    cin >> command;
    if (command == 'P') {
      cin >> alphabet;
      li.insert(cursor, alphabet);
    } else if (command == 'L') {
      if (cursor != li.begin())
        cursor--;
    } else if (command == 'D') {
      if (cursor != li.end())
        cursor++;
    } else if (command == 'B') {
      if (cursor != li.begin()) {
        cursor--;
        cursor = li.erase(cursor);
      }
    }
  }
  for (auto &l : li)
    cout << l;
}