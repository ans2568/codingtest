#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char del) {
  istringstream is(str);
  string buffer;
  vector<string> result;
  while (getline(is, buffer, del)) {
    result.push_back(buffer);
  }
  return result;
}