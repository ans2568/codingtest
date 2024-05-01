#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<char> oper;

int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      cout << str[i];
    } else {
      if (str[i] == '(') {
        oper.push(str[i]);
      } else if (str[i] == '*' || str[i] == '/') {
        while (!oper.empty() && (oper.top() == '*' || oper.top() == '/')) {
          cout << oper.top();
          oper.pop();
        }
        oper.push(str[i]);
      } else if (str[i] == '+' || str[i] == '-') {
        while (!oper.empty() && oper.top() != '(') {
          cout << oper.top();
          oper.pop();
        }
        oper.push(str[i]);
      } else if (str[i] == ')') {
        while (!oper.empty() && oper.top() != '(') {
          cout << oper.top();
          oper.pop();
        }
        oper.pop(); // pop '('
      }
    }
  }
  while (!oper.empty()) {
    cout << oper.top();
    oper.pop();
  }
  cout << endl;
}