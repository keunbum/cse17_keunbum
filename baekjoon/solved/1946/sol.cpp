#include <iostream>
#include <ctime>

using namespace std;

const int N = 123456;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      a[x] = y;
    }
    int ans = 1, mn = a[1];
    for (int i = 2; i <= n; i++) {
      if (mn > a[i]) { mn = a[i]; ans++; cerr << i << '\n';}
    }
    cout << ans << '\n';
  }
  cerr << (float) clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}