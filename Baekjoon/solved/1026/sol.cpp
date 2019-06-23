#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  int ans = 0;
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  for (int i = 0; i < n; i++)
    ans += a[i] * b[i];
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
