#include <iostream>
#include <vector>
using namespace std;

int x[3], y[3];
vector<int> isvisited_x(1001, 0);
vector<int> isvisited_y(1001, 0);
int main() {
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
    isvisited_x[x[i]]++;
    isvisited_y[y[i]]++;
  }
  for (int i=0; i<isvisited_x.size(); i++) {
    if (isvisited_x[i] == 1)
      cout << i << " ";
  }
  for (int i = 0; i < isvisited_y.size(); i++) {
    if (isvisited_y[i] == 1)
      cout << i << endl;
  }
  return 0;
}