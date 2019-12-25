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
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x & 1) { // same
      cout << (get(y) == get(z) ? "YES" : "NO") << '\n';
    } else { // union
      a[get(y)] = get(z);
    }
  }
  return 0;
}