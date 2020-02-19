#include <bits/stdc++.h>

using namespace std;

template <typename T>
int lis(const vector<T> &a) {
  vector<T> u;
  for (const T &x : a) {
    auto it = lower_bound(u.begin(), u.end(), x);
    if (it == u.end()) {
      u.push_back(x);
    } else {
      *it = x;
    }
  }
  return (int) u.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << lis(a) << '\n';
  return 0;
}