#include <iostream>
#include <vector>
using namespace std;

vector<int> A;

int main() {
    A.resize(9);
    for (int i=0; i<9; i++) {
        cin >> A[i];
    }
    int max = 0, idx = 0;
    for (int i=0; i<A.size(); i++) {
        if (max < A[i]) {
            max = A[i];
            idx = i + 1;
        }
    }
    cout << max << endl;
    cout << idx << endl;
    return 0;
}