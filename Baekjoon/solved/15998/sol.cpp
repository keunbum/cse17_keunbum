#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto End = [&](int ans) {
    cout << ans << '\n';
    exit(0);
  };
  int n;
  cin >> n;
  long long M = 0LL;
  long long money = 0LL;
  long long b_max = 0LL;
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    if (a > 0) {
      if (money + a != b) {
        End(-1);
      }
    } else
    if (money + a != b) {
      long long mq = b - (money + a);
      if (mq < 0) {
        End(-1);
      }
      M = __gcd(M, mq);
      b_max = max(b_max, b);
    }
    money = b;
  }
  if (M == 0LL) {
    M = 1LL;
  }
  cout << (M > b_max ? M : -1) << '\n';
  return 0;
}
