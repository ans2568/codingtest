#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vec.resize(N, 0);
    for (int n=0; n<N; n++)
        vec[n] = n+1;
    for (int idx=0; idx<M; idx++) {
        int i, j;
        cin >> i >> j;
        swap(vec[i-1], vec[j-1]);
    }
    for (auto& v : vec)
        cout << v << " ";
    return 0;
}