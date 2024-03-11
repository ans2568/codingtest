#include <iostream>
#include <vector>
using namespace std;

int count = 0;
int main() {
    vector<bool> result;
    result.resize(1001, false);
    for (int i=0; i<10; i++) {
        int num;
        cin >> num;
        num = num % 42;
        result[num] = true;
    }

    for (auto res : result) {
        if (res == true)
            count++;
    }
    cout << count << endl;

    return 0;
}