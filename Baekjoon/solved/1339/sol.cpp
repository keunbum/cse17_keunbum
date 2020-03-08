#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  vector<bool> chk(26, false);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (char c : s[i]) {
      chk[(int) (c - 'A')] = true;
    }
  }
  int m = 0;
  vector<int> order(26, -1);
  for (int i = 0; i < 26; i++) {
    if (chk[i]) {
      order[i] = m++;
    }
  }
  int ans = 0;
  vector<bool> chk_n(10, false);
  function<void(vector<int>&)> Dfs = [&](vector<int>& v) {
    if ((int) v.size() == m) {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        int foo = 0;
        for (char c : s[i]) {
          foo = foo * 10 + v[order[(int) (c - 'A')]];
        }
        sum += foo;
      }
      ans = max(ans, sum);
      return;
    }
    for (int i = 0; i < 10; i++) {
      if (!chk_n[i]) {
        chk_n[i] = true;
        v.push_back(i);
        Dfs(v);
        v.pop_back();
        chk_n[i] = false;
      }
    }
  };
  {
    vector<int> v;
    Dfs(v);
  }
  cout << ans << '\n';
  return 0;
}
