#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int base;
  cin >> s >> base;
  cout << stoi(s, nullptr, base) << '\n';
  return 0;
}