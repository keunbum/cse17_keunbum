#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int a[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  iota(a, a + n, 1);
  k--;
  int p = 0;
  vector<int> ans;
  while (n) {
    p += k;
    p %= n;
    ans.push_back(a[p]);
    rotate(a + p, min(a + p + 1, a + n - 1), a + n);
    n--;
  }
  n = (int) ans.size();
  cout << '<';
  for (int i = 0; i < n; i++) {
    if (i) cout << ", ";
    cout << ans[i];
  }
  cout << '>' << '\n';
  return 0;
}