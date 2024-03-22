#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> result;
vector<string> problem;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    stack<char> stck;
    string answer = "YES";
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(') {
        stck.push(str[i]);
      } else if (!stck.empty() && str[i] == ')' && stck.top() == '(') {
        stck.pop();
      } else {
        answer = "NO";
        break;
      }
    }
    if (!stck.empty())
      answer = "NO";
    result.push_back(answer);
  }
  for (auto &res : result)
    cout << res << endl;
}