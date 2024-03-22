#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, string> is;
typedef pair<int, is> iis;
bool compare(const iis &a, const iis &b) {
  if (a.second.first == b.second.first)
    return a.first < b.first;
  return a.second.first < b.second.first;
}

vector<iis> customer;
int main() {
  int N;
  cin >> N;
  customer.resize(N);
  for (int i = 0; i < N; i++) {
    customer[i].first = i;
    cin >> customer[i].second.first >> customer[i].second.second;
  }
  sort(customer.begin(), customer.end(), compare);
  for (auto &cus : customer)
    cout << cus.second.first << " " << cus.second.second << "\n";
}