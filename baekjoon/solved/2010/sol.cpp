#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 1 - n;
  while (n--) {
    int t;
    cin >> t;
    ans += t;
  }
  cout << ans << '\n';
  return 0;
}