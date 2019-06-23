#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int n, r;
    cin >> n >> r;
    if (!n && !r) break;
    if (r > n - r) {
      r = n - r;
    }
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
      ans = ans * n-- / i;
    }
    cout << ans << '\n';
  }
  return 0;
}