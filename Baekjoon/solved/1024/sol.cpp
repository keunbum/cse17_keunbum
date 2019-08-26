#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  bool ok = false;
  int s = -1, cnt = 0;
  for (int i = l; i <= 100; i++) {
    int t = 2 * n - i * i;
    if (t < -i) {
      continue;
    }
    int q = t / i;
    if ((t % i) == 0 && (q & 1) == 1) {
      ok = true;
      s = (q + 1) / 2;
      cnt = i;
      break;
    }
  }
  if (!ok) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < cnt; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << s + i;
    }
    cout << '\n';
  }
  return 0;
}
