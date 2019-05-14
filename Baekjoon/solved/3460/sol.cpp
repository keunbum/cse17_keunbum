#include <iostream>

using namespace std;

const int BITS = 20;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < BITS; i++) {
      if (n & (1 << i)) {
        cout << i << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}