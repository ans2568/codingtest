#include <iostream>
#include <string>
using namespace std;
int N;
int main() {
    cin >> N;
    string star;
    for (int i=0; i<N; i++) {
        star += "*";
        cout << star << endl;
    }
    return 0;
}