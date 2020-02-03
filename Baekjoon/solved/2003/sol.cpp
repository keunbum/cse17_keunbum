#include <iostream>

using namespace std;

const int N = (int) 1e4 + 10;

int a[N];
int sum[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = a[i - 1] + sum[i - 1];
  }
  sum[n + 1] = a[n] + sum[n];
  int b = 1, e = 2;
  int ans = 0;
  while (e < n + 2) {
//    cerr << b << ' ' << e << ' ' << sum[e] - sum[b] << '\n';
    if (sum[e] - sum[b] == m) {
      ++ans;
      ++b;
      ++e;
    } else
    if (sum[e] - sum[b] < m) {
      ++e;
    } else {
      ++b;
    }
//    cerr << "ans = " << ans << '\n';
  }
  cout << ans << '\n';
  return 0;
}
