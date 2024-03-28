#include <iostream>
#include <string>

using namespace std;

int main() {
  for (int i = 0; i < 100; i++) {
    string str;
    getline(cin, str);
    if (str == "")
      return 0;
    int lower = 0, upper = 0, blank = 0, number = 0;
    for (int j = 0; j < str.size(); ++j) {
      if (str[j] >= 'a' && str[j] <= 'z')
        lower++;
      else if (str[j] >= 'A' && str[j] <= 'Z')
        upper++;
      else if (str[j] >= '0' && str[j] <= '9')
        number++;
      else if (str[j] == ' ')
        blank++;
    }
    cout << lower << " " << upper << " " << number << " " << blank << endl;
  }
}