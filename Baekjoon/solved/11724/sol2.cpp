#include <iostream>
#include <numeric>

using namespace std;

int a[1234];

int f(int x) {
  return x == a[x] ? x : (a[x] = f(a[x]));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  iota(a, a + n, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    if (f(x) != f(y)) {
      n--;
      a[f(x)] = f(y);
    }
  }
  cout << n << '\n';
  return 0;
}