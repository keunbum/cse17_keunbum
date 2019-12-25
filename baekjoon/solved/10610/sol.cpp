#include <bits/stdc++.h>

using namespace std;

int cnt[128];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int foo = 0;
  for (char c : s) {
    cnt[c]++;
    foo += (c - '0');
  }
  bool ok = (cnt['0'] > 0) && (foo % 3 == 0);
  if (ok) {
    for (char i = '9'; i >= '0'; i--) {
      cout << string(cnt[i], i);
    }
    cout << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
