#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> neg;
  vector<int> pos;
  int zero = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0) pos.push_back(x); else
    if (x < 0) neg.push_back(x);
    else ++zero;
  }
  sort(neg.begin(), neg.end());
  sort(pos.rbegin(), pos.rend());
  int ans = 0;
  for (int i = 1; i < (int) neg.size(); i += 2) {
    ans += neg[i - 1] * neg[i];
  }
  if (neg.size() % 2 == 1 && zero == 0) {
    ans += neg.back();
  }
  for (int i = 1; i < (int) pos.size(); i += 2) {
    if (pos[i - 1] == 1) {
      ans += 2;
      continue;
    }
    if (pos[i] == 1) {
      ans += pos[i - 1] + 1;
      continue;
    }
    ans += pos[i - 1] * pos[i];
  }
  if (pos.size() % 2 == 1) {
    ans += 1;
  }
  cout << ans << '\n';
  return 0;
}
