#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cnt[8001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);         
  int n, sum = 0, t, mn = 4000, mx = -4000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    cnt[t + 4000]++;
    mn = min(mn, t);
    mx = max(mx, t);
    sum += t;
  }
  vector<int> v;
  for (int i = mn + 4000; i < mx + 4001; i++) {
    if (!v.empty()) {
      if (cnt[v[0]] < cnt[i]) {
        v.clear();
        v.push_back(i);
      } else
      if (cnt[v[0]] == cnt[i])
        v.push_back(i);  
    }
    else {
      v.push_back(i);
    }
  }
  int i, f = n / 2 + 1;
  for (i = mn + 4000; i < mx + 4001; i++) {
    f -= cnt[i];
    if (f <= 0) break;
  }
  sort(v.begin(), v.end());
  cout << floor(((double) sum) / n + 0.5) << '\n';
  cout << i - 4000 << '\n';
  cout << (v.size() == 1 ? v[0] : v[1]) - 4000 << '\n';
  cout << mx - mn << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
