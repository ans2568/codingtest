#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_accumulate(vector<int> data, int end) {
  int accumulate = 0;
  for (int i = 0; i < end; i++)
    accumulate += data[i];
  return accumulate;
}

int main() {
  // 데이터 개수, 반복 횟수 입력
  int N, M;
  cin >> N >> M;
  // 데이터 입력
  vector<int> data(N, 0);
  for (int i = 0; i < N; i++)
    cin >> data[i];
  // M 번 횟수만큼 반복하여 구간 합 계산
  vector<int> start(M, 0), end(M, 0);
  for (int j = 0; j < M; j++)
    cin >> start[j] >> end[j];
  // 구간 합 구하기(끝 누적 합 - 시작 누적 합)
  for (int j = 0; j < M; j++) {
    // 누적 합
    int start_accumulate = find_accumulate(data, start[j] - 1);
    int end_accumulate = find_accumulate(data, end[j]);
    // 구간 합
    cout << end_accumulate - start_accumulate << endl;
  }
  return 0;
}