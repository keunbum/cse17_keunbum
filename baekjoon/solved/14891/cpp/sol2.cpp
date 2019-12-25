#include <iostream>

using namespace std;

bool a[4][8], t[8];
int d[4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char c;
  int k;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c;
      a[i][j] = c - '0' ? true : false;
    }
  }
  cin >> k;
  while (k--) {
    for (int i = 0; i < 4; i++) d[i] = 0;
    int s;
    cin >> s;
    s--;
    cin >> d[s];
    for (int i = s - 1; i >= 0; i--) {
      if (a[i + 1][6] ^ a[i][2]) d[i] = -d[i + 1];
      else break;
    }
    for (int i = s + 1; i <= 3; i++) {
      if (a[i - 1][2] ^ a[i][6]) d[i] = -d[i - 1];
      else break;
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 8; j++) {
        t[(j + d[i] + 8) % 8] = a[i][j];
      }
      for (int j = 0; j < 8; j++) {
        a[i][j] = t[j];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += a[i][0] << i;
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
