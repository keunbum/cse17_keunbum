#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> m(7981);

inline int add(int x, int t) {
  switch (t) {
    case 0:
      if (++x == 16) x = 1;
      break;
    case 1:
      if (++x == 29) x = 1;
      break;
    case 2:
      if (++x == 20) x = 1;
      break;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(3);
  a[0] = a[1] = a[2] = 1;
  for (int i = 1; i <= 7980; i++) {
    m[i] = a;
    for (int j = 0; j < 3; j++) {
      a[j] = add(a[j], j);
    }
  }
  vector<int> b(3);
  cin >> b[0] >> b[1] >> b[2];
  int i = 1;
  while (1) {
    if (m[i++] == b) break;
  }
  cout << --i << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
