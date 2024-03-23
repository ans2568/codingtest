#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

queue<int> q;
vector<int> result;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    if (str == "push") {
      int in;
      cin >> in;
      q.push(in);
    } else if (str == "front") {
      if (q.empty())
        result.push_back(-1);
      else
      result.push_back(q.front());
    } else if (str == "back") {
      if (q.empty())
        result.push_back(-1);
      else
        result.push_back(q.back());
    } else if (str == "size") {
        result.push_back(q.size());
    } else if (str == "empty") {
      result.push_back(int(q.empty()));
    } else if (str == "pop") {
      if (q.empty())
        result.push_back(-1);
      else {
        result.push_back(q.front());
        q.pop();
      }
    }
  }
  for (auto &res : result)
    cout << res << "\n";
}