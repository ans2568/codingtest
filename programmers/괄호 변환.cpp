#include <string>
#include <vector>

using namespace std;
string dfs(string p);

string solution(string p) {
  string answer = "";
  answer = dfs(p);
  return answer;
}

string dfs(string p) {
  string u = "", v = "";
  int left, right = 0;
  if (p.empty()) {
    return p;
  }
  for (int i = 0; i < p.length();) {
    while (true) {
      if (right != 0 && left != 0 && left == right)
        break;
      if (p[i] == '(')
        right += 1;
      else if (p[i] == ')')
        left += 1;
      u += p[i];
      i++;
    }
    if (i < p.length()) {
      v += p[i];
      i++;
    }
  }
  if (u[0] == '(') {
    // u가 올바른 문자열
    u.append(dfs(v));
  } else if (u[0] == ')') {
    // u가 올바른 문자열이 아님
    string new_u = "";
    new_u += '(';
    new_u += dfs(v);
    new_u += ')';
    u.erase(0, 1);
    u.pop_back();
    for (int i = 0; i < u.length(); i++) {
      if (u[i] == '(')
        new_u += ')';
      else if (u[i] == ')')
        new_u += '(';
    }
    return new_u;
  }
  return u;
}