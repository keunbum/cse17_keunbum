#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<string, int> m;
    while (n--) {
      string x, y;
      cin >> x >> y;
      m[y]++;
    }
    int ans = 1;
    for (auto &e : m) {
      ans *= e.second + 1;
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}