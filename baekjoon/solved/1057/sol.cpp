#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if (a > b) swap(a, b);
  vector<int> v(n);
  int R;
  for (R = 0; (1 << R) < n; R++) ;
  for (int r = 1; r <= R; r++) {
    for (int i = 0; i < (int) v.size(); i++) {
      if (v[i] == a) a = i + 1; else
      if (v[i] == b) b = i + 1;
      v[i] = i + 1;
    }
    if (abs(b - a) == 1 && (a & 1) && !(b & 1)) { cout << r << '\n'; return 0; }
    vector<int> t;
    for (int i = 1; i <= n; i += 2) {
      if (i + 1 != a && i + 1 != b) t.push_back(i);
      else {
        t.push_back(i + 1);
      }
    }
    v = t;
  }
  cout << -1 << '\n';
  return 0;
}