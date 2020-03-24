#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int k;
    cin >> k;
    map<int, int> mp;
    while (k--) {
      char ch;
      cin >> ch;
      if (ch == 'I') {
        int n;
        cin >> n;
        ++mp[n];
      } else {
        int x;
        cin >> x;
        if (mp.empty()) {
          continue;
        }
        if (x == -1) {
          auto it = mp.begin();
          if (--(it->second) == 0) {
            mp.erase(it);
          }
        } else {
          auto it = prev(mp.end());
          if (--(it->second) == 0) {
            mp.erase(it);
          }
        }
      }
    }
    if (mp.empty()) {
      cout << "EMPTY" << '\n';
    } else {
      cout << prev(mp.end())->first << " " << mp.begin()->first << '\n';
    }
  }
  return 0;
}
