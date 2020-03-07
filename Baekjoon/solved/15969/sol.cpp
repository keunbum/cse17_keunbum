#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int mx = 0;
  int mn = 1000;
  while (n--) {
    int x;
    cin >> x;
    mx = max(mx, x);
    mn = min(mn, x);
  }
  cout << mx - mn << '\n';
  return 0;
}
