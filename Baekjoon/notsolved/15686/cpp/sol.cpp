#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 12345;
vector< pair<int, int> > h, c; // house, chicken

inline int dis(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void bt(int m, vector<int> a) {
  int n = a.size();
  int hn = h.size();
  if (m == n) {
    int sum = 0;
    for (int i = 0; i < hn; i++) {
      int mx = 123;
      for (int j = 0; j < n; j++) {
        mx = min(mx, dis(h[i], c[a[j]]));
      }
      sum += mx;
    }
    ans = min(ans, sum);
  } else {
    int cn = c.size();
    int i = n == 0 ? 0 : a[n - 1] + 1;
    for ( ; i < cn; i++) {
      vector<int> b = a;
      b.push_back(i);
      bt(m, b);
    }  
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      int t;
      cin >> t;                             
      if (t == 1) h.emplace_back(x, y); else
      if (t == 2) c.emplace_back(x, y);
    }     
  }
  vector<int> a;
  bt(m, a);
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
