#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int b, c;
  cin >> b >> c;
  unsigned long ans = n;
  for (int i = 0; i < n; i++) {
    int r = a[i] - b;
    if (r > 0) {
      ans += (unsigned long) ceil((double)r / c);
    }
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
