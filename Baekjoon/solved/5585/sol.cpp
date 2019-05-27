#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  n = 1000 - n;
  int a[] = {1, 5, 10, 50, 100, 500};
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += n / a[i];
    n %= a[i];
  }
  cout << ans << '\n';
  return 0;
}