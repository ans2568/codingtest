#include <iostream>
#include <vector>

using namespace std;

int partial_sum(vector<vector<int>> array, int x_1, int y_1, int x_2, int y_2) {
  int x_max = max(x_1, x_2);
  int x_min = min(x_1, x_2);
  int y_max = max(y_1, y_2);
  int y_min = min(y_1, y_2);
  int sum = 0;
  for (int i = x_min - 1; i < x_max; i++) {
    for (int j = y_min-1; j < y_max; j++) {
        sum += array[i][j];
    }
  }
  return sum;
}

int main() {
  // 배열 NxN 중 N, 반복 횟수 M 입력
  int N, M;
  cin >> N >> M;
  vector<vector<int>> array;
  // 데이터 입력
  for (int i = 0; i < N; i++) {
    vector<int> row(N, 0);
    for (int j = 0; j < N; j++)
      cin >> row[j];
    array.push_back(row);
  }
  // 좌표 입력
  vector<int> result;
  for (int i = 0; i < M; i++) {
    int x_1, x_2, y_1, y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    result.push_back(partial_sum(array, x_1, y_1, x_2, y_2));
  }
  for (auto &v : result)
    cout << v << endl;

  return 0;
  }