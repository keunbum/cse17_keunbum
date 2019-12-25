#include <iostream>

using namespace std;

long long a[123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  a[1] = a[2] = a[3] = 1;
  a[4] = a[5] = 2;
  for (int i = 6; i < 101; i++) {
    a[i] = a[i - 1] + a[i - 5];
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << a[n] << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
