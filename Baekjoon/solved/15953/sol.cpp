#include <iostream>

using namespace std;

int x[] = { 500, 300, 200, 50, 30, 10 }; 
int y[] = { 512, 256, 128, 64, 32 };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    if (a == 0) a = 101;
    if (b == 0) b = 65;
    int ans = 0;
    for (int i = 0; i <= 5; i++) {
      a -= i + 1;
      if (a <= 0) {
        ans += x[i];
        break;
      }
    }
    for (int i = 0; i < 5; i++) {
      b -= (1 << i);
      if (b <= 0) {
        ans += y[i];
        break;
      }
    }
    cout << 10000 * ans << '\n';
  }
  return 0;
}
