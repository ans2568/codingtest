#include <iostream>
#include <vector>
using namespace std;

int N, X;
vector<int> A;

int main() {
    cin >> N >> X;
    A.resize(N);
    for (int i=0; i<N; i++)
        cin >> A[i];
    for (auto& a : A) {
        if (a < X)
            cout << a << " ";
    }
    return 0;
}