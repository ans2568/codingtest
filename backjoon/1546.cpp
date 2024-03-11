#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<double> score;

int main() {
  cin >> N;
  score.resize(N);
  int max_score = 0;
  for (int i=0; i<N; i++) {
    double num;
    cin >> num;
    if (num > max_score)
        max_score = num;
    score[i] = num;
  }

  double sum = 0;
  for (int i=0; i<N; i++) {
    score[i] = score[i] / max_score * 100;
    sum += score[i];
  }

  double avg = sum / N;
  cout << avg << endl;

  return 0;
}