#include <iostream>

using namespace std;

const int N = 100;

string s[N];
pair<int, int> a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> a[i].first >> a[i].second;
  }
  int ans = 0;
  for (int i = 123; i <= 987; i++) {
    string f = to_string(i);
    if (f[0] == f[1] || f[1] == f[2] || f[0] == f[2]) continue;
    if (f[1] == '0' || f[2] == '0') continue;
    bool ok = true;
    for (int j = 0; j < n; j++) {
      int st = 0, ba = 0;
      for (int x = 0; x < 3; x++) {
        if (f[x] == s[j][x]) st++;
        for (int y = 0; y < 3; y++) {
          if (x == y) continue;
          if (f[x] == s[j][y]) ba++;
        }
      }
      if (a[j].first != st || a[j].second != ba) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  }
  cout << ans << '\n';
  return 0;
}