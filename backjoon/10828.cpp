#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, stack_size = 0;
int stack[10001] = {-1};
vector<int> result;

void push(int n) {
  stack[stack_size] = n;
  stack_size++;
}
int pop() {
  if (stack_size == 0)
    return -1;
  else {
    int tmp = stack[stack_size - 1];
    stack[stack_size - 1] = -1;
    stack_size--;
    return tmp;
  }
}
int get_size() { return stack_size; }
int is_Empty() {
  if (stack_size == 0)
    return 1;
  else
    return 0;
}
int top() {
  if (stack_size == 0)
    return -1;
  else
    return stack[stack_size - 1];
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    string str;
    cin >> str;
    if (str == "push") {
      cin >> num;
      push(num);
    } else if (str == "pop") {
      result.push_back(pop());
    } else if (str == "size") {
      result.push_back(get_size());
    } else if (str == "empty") {
      result.push_back(is_Empty());
    } else if (str == "top") {
      result.push_back(top());
    }
  }
  for (auto &r : result)
    cout << r << "\n";
}
