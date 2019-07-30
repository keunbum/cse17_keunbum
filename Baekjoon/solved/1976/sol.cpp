#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  iota(a.begin(), a.end(), 0);
  function<int(int)> get = [&](int x) {
    return x == a[x] ? x : (a[x] = get(a[x]));
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int p;
      cin >> p;
      if (p) {
        a[get(i)] = get(j);
      }
    }
  }
  int f;
  cin >> f;
  bool ok = true;
  while (--m) {
    int t;
    cin >> t;
    if (get(f) != get(t)) {
      ok = false;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}