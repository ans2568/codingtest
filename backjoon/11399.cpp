#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> people(N, 0);
    for(int i=0; i<N; i++) {
        cin >> people[i];
    }
    sort(people.begin(), people.end());
    int sum = 0;
    int result = 0;
    for (int i=0; i<N; i++) {
        sum += people[i];
        result += sum;
    }
    cout << result << endl;
    return 0;
}