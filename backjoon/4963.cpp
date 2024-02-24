#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(int h, int w);

int W, H; // width, height
int map[50][50];

int main() {
  while (true) {
    cin >> W >> H;
    if (W == 0 && H == 0)
      break;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cin >> map[i][j];
      }
    }
    int cnt = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (DFS(i, j))
          cnt += 1;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}

bool DFS(int h, int w) {
  if (h <= -1 || w <= -1 || h >= H || w >= W)
    return false;
  if (map[h][w] == 1) {
    map[h][w] = 0;
    DFS(h + 1, w);
    DFS(h + 1, w + 1);
    DFS(h + 1, w - 1);
    DFS(h - 1, w - 1);
    DFS(h - 1, w);
    DFS(h - 1, w + 1);
    DFS(h, w + 1);
    DFS(h, w - 1);
    return true;
  }
  return false;
}