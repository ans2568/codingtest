#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> bucket;
int main() {
    cin >> N >> M;
    bucket.resize(N+1);
    for (int i=1; i<=N; i++)
        bucket[i] = i;
    for (int i=0; i<M; i++) {
        int s, e;
        cin >> s >> e;
        reverse(bucket.begin() + s, bucket.begin() + e + 1);
    }
    for (int a=1; a<=N; a++)
        cout << bucket[a] << " ";
    cout << endl;
    return 0;
}