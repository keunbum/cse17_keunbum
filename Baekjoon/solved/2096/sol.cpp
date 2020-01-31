#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const int inf = (int) 1e9;
int pmx[3], pmn[3], mx[3], mn[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;      
  auto Update = [&](int p) {
    int foo;
    cin >> foo;
    int tmx = 0;
    int tmn = inf;
    for (int i = p - 1; i <= p + 1; i++) {
      if (i >= 0 && i < 3) {
        tmx = max(tmx, pmx[i]);
        tmn = min(tmn, pmn[i]);
      }
    }
    mx[p] = foo + tmx;
    mn[p] = foo + tmn;
  };
  while (n--) {
    for (int i = 0; i < 3; i++) {
      Update(i);
    }
    for (int i = 0; i < 3; i++) {
      pmx[i] = mx[i];
      pmn[i] = mn[i];
    }
  }
  cout << max({mx[0], mx[1], mx[2]}) << ' ' << min({mn[0], mn[1], mn[2]}) << '\n';
  return 0;
}
