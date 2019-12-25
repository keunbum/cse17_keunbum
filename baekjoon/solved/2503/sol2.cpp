#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> ss(n);
  vector<int> st(n), ba(n);
  for (int i = 0; i < n; i++) {
    cin >> ss[i] >> st[i] >> ba[i];
  }
  int ans = 0;
  for (int i = 100; i <= 999; i++) {
    string w = to_string(i);
    if ((w[0] == w[1] || w[1] == w[2] || w[0] == w[2]) || (w[1] == '0' || w[2] == '0')) {
      continue;
    }
    bool ok = true;
    for (int t = 0; t < n; t++) {
      string s = ss[t];
      int m_st = 0;
      int m_ba = 0;
      for (int j = 0; j < 3; j++) {
        if (s[j] == w[j]) {
          m_st++;
        }
        for (int k = 0; k < 3; k++) {
          if (j != k && s[j] == w[k]) {
            m_ba++;
          }
        }
      }
      if (st[t] != m_st || ba[t] != m_ba) {
        ok = false;
        break;
      }
    }
    ans += (int) ok;
  }
  cout << ans << '\n';
  return 0;
}
