#include <iostream>

using namespace std;

int a[20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int t = 1; t < (1 << n); t++) {
    int foo = s;
    for (int i = 0; i < n; i++) {
      foo -= ((t >> i) & 1) * a[i];
    }
    if (foo == 0) ans++;
  }
  cout << ans << '\n';
  return 0;
}