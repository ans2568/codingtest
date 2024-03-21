#include <iostream>
#include <string>
using namespace std;
string WB[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
string BW[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
                "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
int WB_cnt(int x, int y);
int BW_cnt(int x, int y);
char board[51][51];
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  int min_val = 12345;
  for (int i = 0; i + 8 <= N; i++) {
    for (int j = 0; j + 8 <= M; j++) {
      int tmp;
      tmp = min(WB_cnt(i, j), BW_cnt(i, j));
      if (tmp < min_val)
        min_val = tmp;
    }
  }
  cout << min_val << endl;
}

int WB_cnt(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[x + i][y + j] != WB[i][j])
        cnt++;
    }
  }
  return cnt;
}

int BW_cnt(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[x + i][y + j] != BW[i][j])
        cnt++;
    }
  }
  return cnt;
}