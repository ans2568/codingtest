#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> A;
int main() {
    cin >> N;
    A.resize(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<>());
    cout << A[A.size()-1] << " " << A[0] << endl;
    return 0;
}