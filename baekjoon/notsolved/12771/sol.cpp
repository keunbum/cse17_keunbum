#include <bits/stdc++.h>

using namespace std;
 
const int N = (int) 2e3;
 
int xa[N], xb[N], y[N];
 
struct Event {
    int x;
    int y;
    int type;
};
 
inline long long Ccw(int xa, int ya, int xb, int yb, int xc, int yc) {
  return (long long) (xb - xa) * (yc - ya) - (long long) (yb - ya) * (xc - xa);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> xa[i] >> xb[i] >> y[i];
    if (xa[i] > xb[i]) {
      swap(xa[i], xb[i]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < 1; i++) {
    for (int t = 0; t < 1; t++) {
      int x = (t == 0) ? xa[i] : xb[i];
      vector<Event> a;
      for (int j = 0; j < n; j++) {
        if (y[i] != y[j]) {
          if (y[j] > y[i]) {
            a.push_back({-xa[j] + x, y[j] - y[i], xb[j] - xa[j]});
            a.push_back({-xb[j] + x, y[j] - y[i], xa[j] - xb[j]});
          } else {
            a.push_back({xa[j] - x, y[i] - y[j], xa[j] - xb[j]});
            a.push_back({xb[j] - x, y[i] - y[j], xb[j] - xa[j]});
          }
        }
      }
      sort(a.begin(), a.end(), [&](const Event& p, const Event& q) {
        int z = Ccw(0, 0, p.x, p.y, q.x, q.y);
        if (z != 0) {
          return z > 0;
        }
        return p.type > q.type;
      });
      long long sum = xb[i] - xa[i];
      ans = max(ans, sum);
      for (Event& e : a) {
        cerr << e.x << ' ' << e.y << ' ' << e.type << '\n';
        sum += e.type;
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
