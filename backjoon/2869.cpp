#include <ios>
#include <iostream>
using namespace std;

int V, A, B;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> A >> B >> V;
  int day = 1;
  day += (V - A) / (A - B);
  if ((V - A) % (A - B) != 0)
    day++;
  if (A >= V)
    cout << "1" << endl;
  else
   cout << day << endl;
  return 0;
}
