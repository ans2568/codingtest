#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int K, result = 0;
  cin >> K;
  for (int i = 0; i < K; ++i) {
    int n;
    cin >> n;
    if (n == 0) {
      stk.pop();
    } else {
      stk.push(n);
    }
  }
  int stk_size = stk.size();
  for (int i = 0; i<stk_size; ++i) {
    result += stk.top();
    stk.pop();
  }
  cout << result << "\n";
}