#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int a[8];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  iota(a, a + n, 0);
  do {
    for (int i = 0; i < n; i++) {
      if (i > 0) cout << ' ';
      cout << a[i] + 1;
    }
    cout << '\n';
  } while (next_permutation(a, a + n));
  return 0;
}