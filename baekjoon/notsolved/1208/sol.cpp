#include <bits/stdc++.h>

using namespace std;

inline int Cnt(int x, vector<int>& v) {
  return (int) (upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> u, v;
  function<void(int, int, int, vector<int>&)> Dfs = [&](int i, int e, int sum, vector<int>& v) {
    if (i == e) {
      v.push_back(sum);
      return;
    }
    Dfs(i + 1, e, sum + a[i], v);
    Dfs(i + 1, e, sum, v);
  };
  Dfs(0, n >> 1, 0, u);
  Dfs(n >> 1, n, 0, v);
  sort(u.begin(), u.end());
  sort(v.begin(), v.end());
  long long ans = 0;
  for (int x : u) {
    ans += Cnt(s - x, v);
  }
  cout << (ans - (int) (s == 0)) << '\n';
  return 0;
}
