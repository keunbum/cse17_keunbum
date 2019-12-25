#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4 + 1;

int x[N], y[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(1);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  x[n] = x[0];
  y[n] = y[0];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += 1LL * x[i] * y[i + 1] - 1LL * y[i] * x[i + 1];
  }
  cout << (double) abs(ans) * 0.5 << '\n';
  return 0;
}
