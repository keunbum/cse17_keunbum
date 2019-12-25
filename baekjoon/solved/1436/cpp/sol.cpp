#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, cnt = 0;
  cin >> n;
  for (int i = 666; ; i++) {
    int t = i;
    while (t) {
      if (t % 1000 == 666) {
        if (++cnt == n) {
          cout << i << '\n';
          return 0;
        }
        break;
      }
      t /= 10;
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
