#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;
int n, datas[1000001], result[1000001], cnt[1000001] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> datas[i];
    cnt[datas[i]]++;
  }
  for (int i = n - 1; i >= 0; i--) {
    while (!stk.empty() && cnt[datas[i]] >= cnt[stk.top()]) {
      stk.pop();
    }
    if (stk.empty())
      result[i] = -1;
    else
      result[i] = stk.top();
    stk.push(datas[i]);
  }
  // 정답 출력
  for (int i = 0; i < n; i++)
    cout << result[i] << " ";
  cout << "\n";
}