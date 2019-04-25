#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i & 1) cout << ' ';
    for (int j = 0; j < 2 * n - 1; j++) {
      cout << (j & 1 ? ' ' : '*');
      if (j == 2 * n - 2) cout << '\n';
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}