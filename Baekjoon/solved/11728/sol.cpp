#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<int> v(n + m);
  merge(a.begin(), a.end(), b.begin(), b.end(), v.begin());
  for (int x : v) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}