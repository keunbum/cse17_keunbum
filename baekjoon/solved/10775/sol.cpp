#include <iostream>
#include <numeric>

using namespace std;

const int N = (int) 1e5 + 1;

int p[N];

int get(int x) {
  return x == p[x] ? x : (p[x] = get(p[x]));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int g, n;
  cin >> g >> n;
  iota(p, p + g + 1, 0);
  int ans = n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    int x = get(t);
    if (x == 0) { ans = i; break; }
    p[x] = x - 1;
  }
  cout << ans << '\n';
  return 0;
}