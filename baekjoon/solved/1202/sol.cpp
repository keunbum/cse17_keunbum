#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  multiset<int> s;
  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;
    s.insert(t);
  }
  sort(a.begin(), a.end(), [&](const auto a, const auto b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
  });
  long long ans = 0;    
  for (int i = 0; i < n; i++) {
    auto t = s.lower_bound(a[i].first);
    if (t == s.end()) continue;
    s.erase(t);
    ans += a[i].second;
  }
  cout << ans << '\n';
//cerr << (float) clock() / CLOCKS_PER_SEC << " seconds" << '\n';
  return 0;
}