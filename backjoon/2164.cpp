#include <iostream>
#include <queue>
using namespace std;

int N;
int main() {
  queue<int> q;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    q.push(i);
  }
  while (q.size() != 1) {
    q.pop();
    int n = q.front();
    q.pop();
    q.push(n);
  }
  cout << q.front() << endl;

  return 0;
}