#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end(), [&](auto &a, auto &b) { if (a.second == b.second) return a.first < b.first; return a.second < b.second; });
  int ans = 1, e = a[0].second;
  for (int i = 1; i < n; i++) {
    if (e <= a[i].first) { e = a[i].second; ans++; }
  }
  cout << ans << '\n';
  return 0;
}
