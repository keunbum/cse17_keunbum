#include <iostream>

using namespace std;

int a[101][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < 10; i++)
    a[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    a[i][0] = a[i - 1][1];
    for (int j = 1; j < 9; j++) {
      a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % 1000000000;
    }
    a[i][9] = a[i - 1][8];
  } 
  int ans = 0;
  for (int i = 0; i < 10; i++)
    ans = (ans + a[n][i]) % 1000000000;
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
