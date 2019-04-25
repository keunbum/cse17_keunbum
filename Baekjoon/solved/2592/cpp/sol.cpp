#include <iostream>
#include <algorithm>

using namespace std;

int a[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sum = 0, mx = 0, t, mt = 0;
  for (int i = 0; i < 10; i++) {
    cin >> t;
    a[t]++;
    if (a[t] > mx) {
      mx = a[t];
      mt = t;
    }
    sum += t;
  }
  cout << sum / 10 << '\n' << mt << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
