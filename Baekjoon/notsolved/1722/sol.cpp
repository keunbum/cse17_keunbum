#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  int type;
  cin >> type;
  if (type == 1) {
    int k;
    cin >> k;
    --k;
    vector<long long> fact(n, 1);
    for (int i = 1; i < n; i++) {
      fact[i] = fact[i - 1] * i;
    }
    vector<bool> chk(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int t = k / fact[n - 1 - i];
      k %= fact[n - 1 - i];
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (!chk[j]) {
          if (cnt == t) {
            ans[i] = j;
            chk[j] = true;
            break;
          }
          ++cnt;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ans[i] + 1;
    }
    cout << '\n';
  } else {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
  }
  return 0;
}
