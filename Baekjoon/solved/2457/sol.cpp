#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<pair<int, int>, pair<int, int>>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
  }
  sort(a.begin(), a.end());
  pair<int, int> start = { 3, 1 }, end = { 12, 1 }, mx = { 0, 0 };
  bool ok = false;
  int ans = 0, i = 0;
  while (!ok) {
    int mi = -1;
    for ( ; i < n && a[i].first <= start; i++) {
      if (a[i].second <= start) continue;
      if (a[i].second > mx) {
        mi = i;
        mx = a[i].second;
      }
    }
    if (mi == -1) break;
    start = a[mi].second;
    if (a[mi].second >= end) ok = true;
    ans++;
  }
  cout << (ok ? ans : 0) << '\n';
  return 0;
}
