#include <iostream>
#include <algorithm>

using namespace std;

int c[3], m[3];

inline void Move(int x, int y) {
  int z = min(m[x], c[y] - m[y]);
  m[y] += z;
  m[x] -= z;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 3; i++) cin >> c[i] >> m[i];
  for (int i = 0; i < 33; i++) {
    Move(0, 1);
    Move(1, 2);
    Move(2, 0);
  }
  Move(0, 1);
  for (int i = 0; i < 3; i++) cout << m[i] << '\n'; 
  return 0;
}
