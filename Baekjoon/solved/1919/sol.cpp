#include <bits/stdc++.h>

using namespace std;

int cnta[128], cntb[128];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  for (char c : a) {
    cnta[c]++;
  }
  for (char c : b) {
    cntb[c]++;
  }
  int ans = 0;
  for (int i = 'a'; i <= 'z'; i++) {
    ans += abs(cnta[i] - cntb[i]);
  }
  cout << ans << '\n';
  return 0;
}
