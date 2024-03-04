#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num1, num2, num3;

int main() {
    cin >> num1 >> num2 >> num3;

    if (num1 == num2 && num2 == num3)
        cout << 10000 + num1*1000 << endl;
    else if (num1 == num2 || num2 == num3 || num1 == num3)
    {
        int same = 0;
        if (num1 == num2)
            same = num1;
        else if (num2 == num3)
            same = num2;
        else if (num3 == num1)
            same = num3;
        cout << 1000 + same * 100 << endl;
    }
    else {
        vector<int> vec = {num1, num2, num3};
        sort(vec.begin(), vec.end(), greater<>());
        cout << vec[0] * 100 << endl;
    }
    return 0;
}