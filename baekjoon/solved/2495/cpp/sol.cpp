#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 3; i++) {
    int cnt = 1, mx = 0;
    string a;
    cin >> a;
    for (int j = 1; j < 8; j++) {
      if (a[j] == a[j - 1]) {
        cnt++;
      } else {
        cnt = 1;
      }
      mx = max(mx, cnt);
    }
    cout << mx << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
