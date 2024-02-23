#include <iostream>
#include <vector>

using namespace std;

void DFS(int num);

int computer_num, links;
vector<vector<int>> list;
vector<bool> visited;
int count = 0;

int main() {
  cin >> computer_num;
  cin >> links;
  list.resize(computer_num + 1);
  visited = vector<bool>(computer_num + 1, false);
  for (int i = 0; i < links; i++) {
    int s, e;
    cin >> s >> e;
    list[s].push_back(e);
    list[e].push_back(s);
  }

  DFS(1);

  cout << count;

  return 0;
}

void DFS(int num) {
  if (visited[num] == true)
    return;

  visited[num] = true;

  for (size_t i = 0; i < list[num].size(); i++) {
    if (visited[list[num][i]] == false) {
      DFS(list[num][i]);
      count++;
    }
  }
}