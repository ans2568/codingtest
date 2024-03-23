#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    q.push(i);
  cout << "<";
  while (q.size() > 1) {
    for (int i = 1; i < k; i++) {
      int tmp = q.front();
      q.push(tmp);
      q.pop();
    }
    cout << q.front() << ", ";
    q.pop();
  }
  cout << q.front() << ">" << endl;
}