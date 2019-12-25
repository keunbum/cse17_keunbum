#include <iostream>
#include <algorithm>

using namespace std;

int a[12345];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (prev_permutation(a, a + n)) {
    for (int i = 0; i < n; i++) {
      if (i > 0) cout << ' ';
      cout << a[i];
    }
    cout << '\n';
  }
  else cout << -1 << '\n';
  return 0;
}