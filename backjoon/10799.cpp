#include <iostream>
#include <stack>

using namespace std;

int main() {
  string str;
  stack<char> stk;
  getline(cin, str);
  int result = 0;
  stk.push('(');
  for (int i = 1; i < str.size(); i++) {
    if (str[i - 1] == '(' && str[i] == '(') {
      stk.push('(');
    } else if (str[i - 1] == '(' && str[i] == ')') {
      // 레이저일 때
      stk.pop();
      result += stk.size();
    } else if (str[i - 1] == ')' && str[i] == '(') {
      stk.push('(');
    } else if (str[i - 1] == ')' && str[i] == ')') {
      stk.pop();
      result += 1;
    }
  }
  cout << result << endl;
}