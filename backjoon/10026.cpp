#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char graph[101][101];
char graph_redgreen[101][101];

bool DFS_origin(int x, int y, char alphabet);
bool DFS_redgreen(int x, int y, char alphabet, char alphabet2);

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char alphabet;
      cin >> alphabet;
      graph[i][j] = alphabet;
      graph_redgreen[i][j] = alphabet;
    }
  }
  int origin = 0;
  int redgreen = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (DFS_origin(i, j, 'R') || DFS_origin(i, j, 'G') ||
          DFS_origin(i, j, 'B')) {
        origin += 1;
      }
      if (DFS_redgreen(i, j, 'R', 'G') || DFS_redgreen(i, j, 'B', ' ')) {
        redgreen += 1;
      }
    }
  }

  cout << origin << " " << redgreen << endl;
  return 0;
}

bool DFS_origin(int x, int y, char alphabet) {
  if (x <= -1 || y <= -1 || x >= N || y >= N)
    return false;
  if (graph[y][x] == alphabet) {
    graph[y][x] = '1';
    DFS_origin(x + 1, y, alphabet);
    DFS_origin(x - 1, y, alphabet);
    DFS_origin(x, y + 1, alphabet);
    DFS_origin(x, y - 1, alphabet);
    return true;
  }
  return false;
}

bool DFS_redgreen(int x, int y, char alphabet, char alphabet2) {
  if (x <= -1 || y <= -1 || x >= N || y >= N)
    return false;
  if (graph_redgreen[y][x] == alphabet || graph_redgreen[y][x] == alphabet2) {
    graph_redgreen[y][x] = '1';
    DFS_redgreen(x + 1, y, alphabet, alphabet2);
    DFS_redgreen(x - 1, y, alphabet, alphabet2);
    DFS_redgreen(x, y + 1, alphabet, alphabet2);
    DFS_redgreen(x, y - 1, alphabet, alphabet2);
    return true;
  }
  return false;
}