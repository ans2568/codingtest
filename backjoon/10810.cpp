#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vec;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vec.resize(N, 0);
    for (int idx=0; idx<M; idx++) {
        int i, j, k;
        cin >> i >> j >> k;
        for (int start=i-1; start<=j-1; start++) {
            vec[start] = k;
        }
    }
    for (auto& v : vec)
        cout << v << " ";
    return 0;
}