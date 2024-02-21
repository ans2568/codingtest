#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> vec(N, 0);
    for (int i=0; i<N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (auto & v : vec) 
        cout << v << endl;
    return 0;
}