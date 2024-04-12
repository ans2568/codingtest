#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N;
vector<vector<int>> graph;
bool visited[101];

void dfs(int n) {
  for (int i = 0; i < graph[n].size(); ++i) {
    if (!visited[graph[n][i]]) {
        visited[graph[n][i]] = true;
        dfs(graph[n][i]);
    }
  }
}

int main() {
  cin >> N;
  graph.resize(N + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      int input;
      cin >> input;
      if (input == 1) {
        graph[i].push_back(j);
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    memset(visited, false, sizeof(visited));
    dfs(i);
    for (int j = 1; j <= N; ++j) {
      cout << visited[j] << " ";
    }
    cout << "\n";
  }
}