#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <tuple>

using namespace std;

vector<int> p;

int get(int x) {
  return x == p[x] ? x : (p[x] = get(p[x]));
}

bool unite(int a, int b) {
  a = get(a);
  b = get(b);
  if (a == b) return false;
  p[a] = b;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  p.resize(n);
  iota(p.begin(), p.end(), 0);
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> s;                      
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    s.emplace(z, x, y);
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    tuple<int, int, int> e;
    do {
      e = s.top();
      s.pop();
    } while (!unite(get<1>(e), get<2>(e)));
    ans += get<0>(e);
  }
  cout << ans << '\n';
  return 0;
}