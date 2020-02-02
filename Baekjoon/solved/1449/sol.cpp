#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = (int) 1e9;
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int last = -inf;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] - last >= l) {
      last = a[i];
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
