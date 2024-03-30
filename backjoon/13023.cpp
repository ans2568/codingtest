#include <iostream>
#include <vector>
#define MAX_SIZE 2000
using namespace std;

int N, M;
vector<vector<int>> graph;
bool visited[MAX_SIZE];
bool success = false;

void dfs(int n, int depth) {
  if (depth == 5 || success) {
    success = true;
    return;
  }
  visited[n] = true;
  for (int i = 0; i < graph[n].size(); i++) {
    if (visited[graph[n][i]] == false) {
      dfs(graph[n][i], depth+1);
    }
  }

  // KEY POINT : 이전에 방문한 내용이더라도 다시 재방문이 가능하도록
  // 변경해야하기 때문에 false로 초기화 필요
  visited[n] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  graph.resize(N);
  for (int i = 0; i < M; i++) {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }
  for (int i = 0; i < N; i++)
    dfs(i, 1);

  if (success)
    cout << 1 << "\n";
  else
    cout << 0 << "\n";
}