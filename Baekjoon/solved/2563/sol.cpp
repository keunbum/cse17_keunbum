#include <iostream>

using namespace std;

int a[123][123];
     
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        a[x + i][y + j] |= 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      ans += a[i][j];
    }
  }
  cout << ans << '\n';
  return 0;
}
