#include <iostream>

using namespace std;

int f[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  f[0] = f[1] = 1;
  for (int i = 2; i < 1001; i++)
    f[i] = (f[i - 2] + f[i - 1]) % 10007;
  cin >> n;
  cout << f[n] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
