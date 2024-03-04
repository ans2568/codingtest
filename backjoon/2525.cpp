#include <iostream>
using namespace std;
int A, B, C;

int main() {
    cin >> A >> B >> C;
    if (B + C >= 60) 
        A += (B+C) / 60;
    B = (B+C) % 60;
    if (A >= 24)
        A -= 24;
    cout << A << " " << B << endl;
    return 0;
}