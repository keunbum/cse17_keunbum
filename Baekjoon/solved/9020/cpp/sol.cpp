#include <iostream>
#include <utility>

using namespace std;

bool nprime[10001];
pair<int, int> a[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  nprime[1] = true;
  for (int i = 2; i < 10001; i++) {
    if (nprime[i]) continue;
    for (int j = 2 * i; j < 10001; j += i) {
      nprime[j] = true;
    }
  }
  for (int i = 2; i < 10001; i += 2) {
    for (int j = i / 2; j >= 2; j--) {
      if (nprime[j] || nprime[i - j]) continue;
      a[i].first = j;
      a[i].second = i - j;
      break;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << a[n].first << ' ' << a[n].second << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
