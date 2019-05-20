#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char c;
  while (cin.get(c)) {
    c -= 3;
    if (c < 'A') c += 26;
    cout << c;
  }
  return 0;
}