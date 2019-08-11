#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), sum(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j < i; j++) {
      if (a[i] > a[j]) {
        sum[i] = max(sum[i], sum[j]);
      }
    }
    sum[i] += a[i];
    ans = max(ans, sum[i]);
  }
  cout << ans << '\n';
  return 0;
}