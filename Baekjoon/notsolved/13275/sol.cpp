#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> ans(n + n - 1);
  int l = -1, r = -1;
  int mx = 1;
  for (int z = 0; z < n + n - 1; z++) {
    cerr << "l = " << l << " r = " << r << '\n';
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, ans[2 * (l + r) - z]));
    cerr << "i = " << i << " j = " << j << " p = " << p << '\n';
    while (j + p + 1 < n && i - p - 1 >= 0 && s[j + p + 1] == s[i - p - 1]) {
      p++;
    }
    cerr << "p = " << p << '\n';
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    ans[z] = p;
    mx = max(mx, ans[z] * 2 + !(z & 1));
  }
  cout << mx << '\n';
  return 0;
}
