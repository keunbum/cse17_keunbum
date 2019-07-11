#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  do {
    int x;
    for (x = 1; x < m; x++) {
      if (a[x - 1] > a[x]) break;
    }
    if (x >= m) {
      for (int i = 0; i < m; i++) {
        cout << (i ? " " : "") << a[i];
      }
      cout << '\n';
    }
    sort(a.rbegin(), a.rend() - m);
  } while (next_permutation(a.begin(), a.end()));
  return 0;
}