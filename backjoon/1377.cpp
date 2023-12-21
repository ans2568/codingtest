#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> A(N, {0, 0}); // 데이터 값, 각 배열의 인덱스를 저장
  for (int i = 0; i < N; i++) {
    cin >> A.at(i).first; // 값 저장
    A.at(i).second = i; // 값에 해당하는 인덱스를 저장
  }

  sort(A.begin(), A.end()); // 정렬

  int max = -1;
  for (int i = 0; i < N; i++) {
    if (max < A.at(i).second - i) // 정렬된 인덱스 - 현재 인덱스 = swap 된 횟수
      max = A.at(i).second - i; // swap 된 횟수의 최대 값 찾기
  }
  cout << max + 1 << endl; // swap 된 횟수 + 1 이 최종 출력

  return 0;
}