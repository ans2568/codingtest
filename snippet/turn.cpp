#include <iostream>
#include <vector>

using namespace std;

// 주어진 행렬의 일부분을 시계방향으로 회전하는 함수
void rotateSquare(vector<vector<int>> &matrix, int min_y, int min_x, int max_y,
                  int max_x) {
  int n = max_y - min_y + 1;
  vector<vector<int>> temp(n, vector<int>(n)); // 임시 행렬 생성

  // 주어진 부분을 temp로 복사 및 회전
  for (int i = min_y; i <= max_y; ++i) {
    for (int j = min_x; j <= max_x; ++j) {
      temp[i - min_y][j - min_x] = matrix[i][j];
    }
  }

  // 회전된 값을 원래 행렬로 복사
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      matrix[min_y + i][min_x + j] = temp[n - j - 1][i];
    }
  }
}

// 정사각형을 선택하는 함수
void selectSquareToRotate(vector<vector<int>> &matrix, int min_y, int min_x,
                          int max_y, int max_x) {
  rotateSquare(matrix, min_y, min_x, max_y, max_x);
}

// 행렬을 출력하는 함수
void printMatrix(const vector<vector<int>> &matrix) {
  for (const auto &row : matrix) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> matrix = {
      {1, 2, 3, 4, 5, 6},       {8, 9, 10, 11, 12, 13},
      {14, 15, 16, 17, 18, 19}, {20, 21, 22, 23, 24, 25},
      {26, 27, 28, 29, 30, 31}, {32, 33, 34, 35, 36, 37}};

  // 선택한 정사각형 회전
  selectSquareToRotate(matrix, 2, 3, 4, 5);

  // 결과 출력
  printMatrix(matrix);

  return 0;
}