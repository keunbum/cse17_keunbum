#include <iostream>

using namespace std;

int a[123456][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  a[1][0] = a[1][1] = 1;
  for (int i = 2; i < 111111; i++) {
    a[i][0] = (a[i - 1][0] + 2 * a[i - 1][1]) % 9901;
    a[i][1] = (a[i - 1][0] + a[i - 1][1]) % 9901;
  }
  int n;
  cin >> n;
  cout << (a[n][0] + 2 * a[n][1]) % 9901 << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
