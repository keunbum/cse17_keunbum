#include <iostream>
#include <algorithm>

using namespace std;

inline int p(int n) {
  return n * n;
}

int a[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    if (!a[0]) break;
    sort(a, a + 3);
    cout << (p(a[2]) == p(a[0]) + p(a[1]) ? "right" : "wrong") << '\n';
  }
  return 0;
}