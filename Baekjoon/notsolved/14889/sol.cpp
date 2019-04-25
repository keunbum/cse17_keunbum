#include <iostream>

using namespace std;

int a[22], d[11][40004];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n;
  d[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> t;
      a[i] += t;
      a[j] += t;
    }
  }
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += a[i];
    for (int j = (i < (n / 2) - 1) ? i : (n / 2) - 1; j >= 0; j--)
      for (int k = (40000 < s ? 40000 : s) - a[i]; k >= 0; k--)
        if (d[j][k]) d[j + 1][k + a[i]] = 1;
  }
  s /= 2;
  int i;
  for (i = s; !d[n / 2][i]; i--)
    ;
  cout << s - i << '\n'; 
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
