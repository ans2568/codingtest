#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

vector<pair<int, int>> nodes[MAX]; // 연결된 정점 번호, 정점에서 연결된 정점까지의 거리
int V; // 정점 개수, 정점 번호, 연결된 정점 번호, 정점에서 연결된 정점까지의 거리
queue<pair<int, int>> queue_;
int max_distance = 0;
bool visited[MAX];
int max_distance_node = 1;

void bfs(int node, int cost) {
  queue_.push(make_pair(node, cost));
  while (!queue_.empty()) {
    node = queue_.front().first;
    cost = queue_.front().second;
    visited[node] = true;
    queue_.pop();
    for (int i = 0; i < nodes[node].size(); i++) {
      int next = nodes[node].at(i).first;
      int nextcost = nodes[node].at(i).second;
      if (!visited[next]) {
        queue_.push(make_pair(next, cost + nextcost));
        if (cost + nextcost > max_distance) {
          max_distance = cost + nextcost;
          max_distance_node = next;
        }
      }
    }
  }
}

int main() {
  cin >> V;
  for (int i = 1; i <= V; i++) {
    int num, link, dist;
    cin >> num;
    cin >> link;
    while (link != -1) {
      cin >> dist;
      nodes[num].push_back(make_pair(link, dist));
      nodes[num].push_back(make_pair(num, dist));
      cin >> link;
    }
  }
    bfs(1, 0);
    memset(visited, false, sizeof(visited));
    bfs(max_distance_node, 0);
    cout << max_distance << "\n";
  return 0;
}