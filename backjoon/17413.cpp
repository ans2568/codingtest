#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reverse_print(stack<char> &stk) {
  while (!stk.empty()) {
    cout << stk.top();
    stk.pop();
  }
}

int main() {
  string str;
  stack<char> stk;
  getline(cin, str);
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '<') {
      reverse_print(stk);
      while (true) {
        cout << str[i];
        if (str[i] == '>')
          break;
        i++;
      }
    } else if (str[i] == ' ') {
      reverse_print(stk);
      cout << " ";
    } else {
      stk.push(str[i]);
    }
  }
  reverse_print(stk);
}