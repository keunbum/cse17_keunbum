#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int n;
    cin >> n;
    if (n == -1) {
      break;
    }
    vector<int> ans;
    ans.push_back(1);
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        ans.push_back(i);
        if (i * i != n)) {
          ans.push_back(n / i);
        }
      }
    }
    sort(ans.begin(), ans.end());
    long long sum = accumulate(ans.begin(), ans.end(), 0LL);
    if (sum == n) {
      cout << n << " = ";
      int m = (int) ans.size();
      for (int i = 0; i < m; i++) {
        if (i > 0) {
          cout << " + ";
        }
        cout << ans[i];
      }
      cout << '\n';
    } else {
      cout << n << " is NOT perfect." << '\n';
    }
  }
  return 0;
}
