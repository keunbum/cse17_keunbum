#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t, a = 0, sum = 0;
  cin >> n;
  while (n--) {
    cin >> t;
    a = t * (++a);
    sum += a;
  }
  cout << sum << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
