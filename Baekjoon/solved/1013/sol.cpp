#include <bits/stdc++.h>

using namespace std;

bool Dfs(const string& s, int i, int n) {
//  cerr << "i = " << i << endl;
  if (i >= n) {
    if (i == n) return true;
    return false;
  }
  if (i + 1 < n && s.substr(i, 2) == "01") {
    return Dfs(s, i + 2, n);
  }
  if (i + 2 >= n || s.substr(i, 3) != "100") {
    return false;
  }
  i += 3;
  while (i < n && s[i] == '0') {
    ++i;
  }
  if (i >= n) {
    return false;
  }
  while (i < n && s[i] == '1') {
    ++i;
  }
  if (!Dfs(s, i, n)) {
    if (s[i - 2] == '1') return Dfs(s, i - 1, n);
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    cout << (Dfs(s, 0, (int) s.size()) ? "YES" : "NO") << '\n';
  }
  return 0;
}
