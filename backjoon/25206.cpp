#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<double> grad;
double score_sum = 0;
int main() {
  for (int i = 0; i < 20; i++) {
    string name, grade;
    double score;
    cin >> name >> score >> grade;
    if (grade != "P")
        score_sum += score;
    if (grade == "A+")
      score *= 4.5;
    else if (grade == "A0")
      score *= 4.0;
    else if (grade == "B+")
      score *= 3.5;
    else if (grade == "B0")
      score *= 3.0;
    else if (grade == "C+")
      score *= 2.5;
    else if (grade == "C0")
      score *= 2.0;
    else if (grade == "D+")
      score *= 1.5;
    else if (grade == "D0")
      score *= 1.0;
    else if (grade == "F")
      score *= 0.0;
    else
      continue;
    grad.push_back(score);
  }
  double result = 0;
  for (auto &s : grad) {
    result += s;
  }
  cout << result / score_sum << endl;

  return 0;
}