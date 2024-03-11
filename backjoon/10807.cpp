#include <iostream>
#include <vector>
using namespace std;

int N, v;
vector<int> vec;

int main() {
    cin >> N;
    vec.resize(N);
    for (int i=0; i<N; i++) {
        cin >> vec[i];
    }
    cin >> v;
    int cnt = 0;
    for (auto& r : vec) {
        if (v == r)
            cnt++;
    }
    cout << cnt << endl;
}