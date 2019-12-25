#include <iostream>

using namespace std;

const int inf = (int) 1e9;

int a[1234], d[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    d[i] = inf;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (d[j] >= a[i]) {
        d[j] = a[i];
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (d[i] < inf && d[i] > 0) ans++;
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}