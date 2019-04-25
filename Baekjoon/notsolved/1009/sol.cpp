#include <iostream>

using namespace std;

int f(int a, int b) {
  if (b == 1) return a % 10;
  int h = f(a, b / 2);
  if (b & 1) {
    return (h * h * (a % 10)) % 10;
  }
  return (h * h % 10);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    int ret = f(a, b);
    if (ret == 0) ret = 10;
    cout << ret << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
