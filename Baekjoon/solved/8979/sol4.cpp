#include <iostream>

using namespace std;

struct Country {
  int x, y, z;
  bool operator<(const Country &o) const {
    if (x != o.x) return x < o.x;
    if (y != o.y) return y < o.y;
    if (z != o.z) return z < o.z;
    return false;
  }
};

Country a[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int j;
    cin >> j;
    cin >> a[j].x >> a[j].y >> a[j].z;
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (a[k] < a[i]) ans++;
  }
  cout << ans << '\n';
  return 0;
}