#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  const int md = 1234567891;
  const int r = 31;
  long long h = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    ans = (ans + (c - 'a' + 1) * h) % md;
    h = (h * r) % md;
  }
  cout << ans << '\n';
  return 0;
}
