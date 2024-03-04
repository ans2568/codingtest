#include <iostream>
using namespace std;
int h, m;

int main() {
    cin >> h >> m;
    if (m < 45) {
        if (h == 0)
            h = 23;
        else h -= 1;
        m += 15;
    } else {
        m -= 45;
    }
    cout << h << " " << m << endl;
    return 0;
}