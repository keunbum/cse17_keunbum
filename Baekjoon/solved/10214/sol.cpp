#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int Y = 0, K = 0;
    for (int i = 0; i < 9; i++) {
      int y, k;
      cin >> y >> k;
      if (y != k) {
        if (y > k) Y++;
        else K++;
      }
    }
    cout << (Y == K ? "Draw" : Y > K ? "Yonsei" : "Korea") << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}