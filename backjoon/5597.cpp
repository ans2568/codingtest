#include <iostream>
#include <vector>

using namespace std;
vector<bool> students;

int main() {
    students.resize(31, false);
    for (int i=0; i<28; i++) {
        int num;
        cin >> num;
        students[num] = true;
    }
    for (int i=1; i < students.size(); i++) {
        if (students[i] == false)
            cout << i << endl;
    }

    return 0;
}