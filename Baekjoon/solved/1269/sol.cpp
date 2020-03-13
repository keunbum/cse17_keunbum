#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<int> a;
  while (n--) {
    int x;
    cin >> x;
    a.insert(x);
  }
  set<int> b;
  while (m--) {
    int y;
    cin >> y;
    auto it = a.find(y);
    if (it != a.end()) {
      a.erase(it);
    } else {
      b.insert(y);
    }
  }
  cout << a.size() + b.size() << '\n';
  return 0;
}
