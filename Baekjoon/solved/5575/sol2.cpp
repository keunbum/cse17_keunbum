#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a[4], b[4];
  int tt = 3;
  while (tt--) {
    cin >> a[1] >> a[2] >> a[3];
    cin >> b[1] >> b[2] >> b[3];
    for (int i = 3; i > 0; i--) {
      b[i] -= a[i];
      if (b[i] < 0) {
        b[i] += 60;
        b[i - 1]--;
      }
    } 
    cout << b[1] << ' ' << b[2] << ' ' << b[3] << '\n';
  }
  return 0;
}