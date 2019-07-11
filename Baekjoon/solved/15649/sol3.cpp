#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  do {
    for (int i = 0; i < m; i++) {
      if (i) cout << ' ';
      cout << a[i];
    }
    cout << '\n';
    sort(a.rbegin(), a.rend() - m);
  } while (next_permutation(a.begin(), a.end()));
  return 0;
}