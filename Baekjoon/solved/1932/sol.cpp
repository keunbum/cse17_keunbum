#include <iostream>
#include <algorithm>

using namespace std;

const int N = 500 * 501 / 2;

int a[N + 1];
long long sum[N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int x = i * (i - 1) / 2 + j - 1;
      int y = x + 1;
      int z = y + i;
      long long s = 0;
      if (j != 0) s = max(s, sum[x]);
      if (j != i) s = max(s, sum[y]);
      cin >> a[z];
      sum[z] = a[z] + s;
      ans = max(ans, sum[z]);
    }
  }
  cout << ans << '\n';
  return 0;
}