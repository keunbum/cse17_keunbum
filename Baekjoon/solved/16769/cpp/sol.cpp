#include <iostream>
#include <algorithm>

using namespace std;

int c[3], m[3];

inline void move(int p, int n) {
  int s = min(c[n] - m[n], m[p]);
  m[n] += s;
  m[p] -= s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 3; i++)
    cin >> c[i] >> m[i];
  for (int i = 0; i < 33; i++) {
    move(0, 1);
    move(1, 2);
    move(2, 0);
  }
  move(0, 1);
  cout << m[0] << '\n';
  cout << m[1] << '\n';
  cout << m[2] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
