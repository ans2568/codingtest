#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int a);
int N, M;
static vector<vector<int>> node;
static vector<bool> visited;

int main() {
    cin >> N >> M;
    // index 0은 사용하지 않으므로 배열을 하나 더 추가해서 사용
    node.resize(N+1);
    visited = vector<bool>(N+1, false);
    for (int i=0; i<M; i++) {
        int s, e;
        cin >> s >> e;
        // 무방향 그래프
        node[s].push_back(e);
        node[e].push_back(s);
    }
    int cnt = 0;

    for (int i=1; i<N+1; i++) {
        if (!visited[i]) {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << endl;
    return 0;
}

void DFS(int num) {
    if (visited[num])
        return;
    visited[num] = true;
    for (int i : node[num]) {
        if (visited[i] == false)
            DFS(i);
    }
}