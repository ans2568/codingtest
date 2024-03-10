#include <iostream>
#include <vector>
using namespace std;

int A, B;
vector<pair<int, int>> v;

int main() {
    while(true) {
        cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        else
            v.push_back(make_pair(A, B));
    }
    for (auto& e : v)
        cout << e.first + e.second << endl;

    return 0;
}