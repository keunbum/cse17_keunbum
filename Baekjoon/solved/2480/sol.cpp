#include <iostream>
#include <algorithm>

using namespace std;

int a[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int &t : a) {
    cin >> t;
  }
  sort(a, a + 3);
  if (a[0] == a[1]) {
    if (a[1] == a[2]) {
      cout << (int) 1e4 + a[0] * (int) 1e3 << '\n';
    } else {
      cout << (int) 1e3 + a[0] * (int) 1e2 << '\n';
    }
  } else
  if (a[1] == a[2]) {
    cout << (int) 1e3 + a[1] * (int) 1e2 << '\n';
  } else {
    cout << a[2] * (int) 1e2 << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}