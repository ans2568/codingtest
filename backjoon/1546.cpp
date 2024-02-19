#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  int *scores = new int[N];
  // 입력
  for (int i = 0; i < N; i++) {
    cin >> scores[i];
  }

  vector<int> score_vec;
  for (int i = 0; i < N; i++)
    score_vec.push_back(scores[i]);
  // 최댓값 찾기
  auto max_ = max_element(score_vec.begin(), score_vec.end());
  vector<double> new_scores;
  // 점수 치환
  for (auto &s : score_vec) {
    double new_s = (static_cast<double>(s) / *max_.base()) * 100.0;
    new_scores.push_back(new_s);
  }
  // 평균 구하기
  double sum = 0;
  for (auto &ns : new_scores) {
    sum += ns;
  }
  cout.precision(8);
  cout << sum / N << endl;

  return 0;
}