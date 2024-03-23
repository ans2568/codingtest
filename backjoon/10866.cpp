#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque<int> dq;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    int in;
    cin >> str;
    if (str == "push_front") {
      cin >> in;
      dq.push_front(in);
    } else if (str == "push_back") {
      cin >> in;
      dq.push_back(in);
    } else if (str == "pop_front") {
      if (dq.empty())
        cout << "-1"
             << "\n";
      else {
        cout << dq.front() << "\n";
        dq.pop_front();
      }
    } else if (str == "pop_back") {
      if (dq.empty())
        cout << "-1"
             << "\n";
      else {
        cout << dq.back() << "\n";
        dq.pop_back();
      }
    } else if (str == "size") {
        cout << dq.size() << "\n";
    } else if (str == "empty") {
        cout << int(dq.empty()) << "\n";
    } else if (str == "front") {
      if (dq.empty())
        cout << "-1"
             << "\n";
      else
        cout << dq.front() << "\n";
    } else if (str == "back") {
      if (dq.empty())
        cout << "-1"
             << "\n";
      else
        cout << dq.back() << "\n";
    }
  }
}