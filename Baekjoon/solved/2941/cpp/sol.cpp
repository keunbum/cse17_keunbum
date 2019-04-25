#include <iostream>
#include <string>

using namespace std;

string m[] = { "dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z=" };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ans = 0, n;
  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    if (i == 0) ans++;
    else {
      int j;
      for (j = 0; j < 8; j++) {
        if (s.substr(i - 1, 2) == m[j]) {
          break;
        }
      }
      if (j == 8) ans++;
      else if (i > 1 && s.substr(i - 2, 3) == m[0]) ans--;
    }
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
