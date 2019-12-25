#include <iostream>
#include <numeric>

using namespace std;

int a[21];

inline void reverse(int b, int e) {
  while (b <= e) {
    int t = a[b];
    a[b++] = a[e];
    a[e--] = t;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  iota(a, a + 21, 0);
  for (int i = 0; i < 10; i++) {
    int s, e;
    cin >> s >> e;
    reverse(s, e);
  }
  for (int i = 1; i < 20; i++) {
    cout << a[i] << ' ';
  }
  cout << a[20] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
