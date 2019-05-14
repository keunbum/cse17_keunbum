#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

const int N = 100000;

int a[N];

int solve(int n) {
  int mx = a[0];
  for (int i = 1; i < n; i++) {
    a[i] = max(a[i], a[i] + a[i - 1]);
    mx = max(mx, a[i]);
  }
  return mx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << solve(n) << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
