#include <iostream>

using namespace std;
             
int n, m, k;
const int N = (int) 1e6;
const int MAX = N * 2 - 1;

int a[N + 1];
long long v[MAX + 1];

void add(int pos, int d) {
  cerr << "add()" << '\n';
  while (pos <= 2 * n - 1) {
    cerr << pos << '\n';
    v[pos] += d;
    pos += pos & (-pos);
  }
}

long long sum(int pos) {
  cerr << "sum()" << '\n';
  long long r = 0;
  while (pos > 0) {
    cerr << pos << '\n';
    r += v[pos];
    pos -= pos & (-pos);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(i, a[i]);
  }
  m += k;
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x & 1) {
      add(y, z - a[y]);
      a[y] = z;
    } else {
      cout << sum(z) - sum(y - 1) << '\n';
    }
  }
  return 0;
}