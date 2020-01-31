#include <iostream>

using namespace std;

int f[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  while (n--) {
    int x, y;
    cin >> x >> y;
    for (int i = k; i >= x; i--) {
      f[i] = max(f[i], f[i - x] + y);
    }
  }
  cout << f[k] << '\n';
  return 0;
}