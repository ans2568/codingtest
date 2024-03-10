#include <iostream>
#include <vector>
using namespace std;
int X, N;
vector<int> a, b;
int main() {
    cin >> X >> N;
    a.resize(N, 0);
    b.resize(N, 0);
    int result = 0;
    for (int i = 0; i<N; i++) {
        cin >> a[i] >> b[i];
        result += a[i] * b[i];
    }
    if (X == result)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}