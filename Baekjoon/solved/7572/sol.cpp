#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  int i = 0, j = 0, nn = 60;
  while (nn--) {
    cerr << ++cnt << ": " << (char) ('A' + i++) << j++ << '\n';
    if (i == 12) i -= 12;
    if (j == 10) j -= 10;
  }
  cout << (char) ((n ) % 12 + 'A') << (n ) % 10 << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
