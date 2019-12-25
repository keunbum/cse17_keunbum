#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a[6];
  int tt = 3;
  while (tt--) {
    for (int i = 0; i < 6; i++) {
      cin >> a[i];
    }
    for (int i = 5; i > 2; i--) {
      a[i] -= a[i - 3];
      if (a[i] < 0) {
        a[i] += 60;
        a[i - 1]--;
      }
    }
    cout << a[3] << ' ' << a[4] << ' ' << a[5] << '\n';
  }
  return 0;
}