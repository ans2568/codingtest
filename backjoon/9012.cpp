#include <iostream>
#include <string>
#include <stack>
using namespace std;

int T;
int main() {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    stack<char> stk;
    string str;
    cin >> str;
    for (int j = 0; j < str.size(); ++j) {
      if (stk.empty()) // 스택이 비어있을 때
        stk.push(str[j]);
      else {
        if (stk.top() == '(' && str[j] == ')') {
          stk.pop();
        } else {
          stk.push(str[j]);
        }
      }
    }
    if (stk.empty())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}