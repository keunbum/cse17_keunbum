#include <iostream>
#include <ctime>

using namespace std;

int main() {
  int tt = 99	;
  cout << tt << '\n';
  while (tt--) {
    int n = 99;
    for (int i = 0; i < n; i++) {
      if (i) cout << ' ';
      cout << rand() % (int) 2e9;
    }
    cout << '\n';
  }
  return 0;
}