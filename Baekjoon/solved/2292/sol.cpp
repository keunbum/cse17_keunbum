#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int e, i;
  e = 1;
  for (i = 0; ; i++) {
    e += 6 * i;
    if (n <= e)
      break;
  }
  cout << i + 1 << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
