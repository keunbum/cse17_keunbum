#include <iostream>

using namespace std;
             
const int N = (int) 1e6 + 1;
const int MAX = 1 << 20;

long long a[N], v[MAX + 1];

void add(int idx, long long diff) {
  while (idx <= MAX) {
    v[idx] += diff;
    idx += idx & (-idx);
  }
}

long long sum(int idx) {
  long long r = 0;
  while (idx > 0) {
    r += v[idx];
    idx -= idx & (-idx);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(i, a[i]);
  }
  m += k;
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x & 1) {
      long long z;
      cin >> z;
      add(y, z - a[y]);
      a[y] = z;
    } else {
      int z;
      cin >> z;
      cout << sum(z) - sum(y - 1) << '\n';
    }
  }
  return 0;
}