#include <iostream>
#include <string>
using namespace std;

int N;

int main() {
    cin >> N;
    string result;
    int num = N/4;
    for (int i=0; i<num; i++)
        result += "long ";
    cout << result + "int" << endl;
    return 0;
}