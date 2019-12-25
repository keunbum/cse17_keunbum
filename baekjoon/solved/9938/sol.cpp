#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  vector<int> p(l + 1);
  vector<bool> chk(l + 1, false);
  iota(p.begin(), p.end(), 0);
  function<int(int)> get = [&](int v) {
    return v == p[v] ? v : (p[v] = get(p[v]));
  };
  auto unite = [&](int X, int Y) {
    cout << "LADICA" << '\n';
    p[X] = Y;
  };
  while (n--) {
    int x, y;
    cin >> x >> y;
    int X = get(x);
    int Y = get(y);
    if (!chk[x]) { chk[x] = true; unite(X, Y); } else
    if (!chk[y]) { chk[y] = true; unite(Y, X); } else
    if (!chk[X]) { chk[X] = true; unite(X, Y); } else
    if (!chk[Y]) { chk[Y] = true; unite(Y, X); } else
    cout << "SMECE" << '\n';
  }
  return 0;
}