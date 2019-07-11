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
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    /*
    for (int i = 0; i < m; i++) {
      cout << (i ? " " : "") << a[i];
    }
    */
    cout << '\n';
    sort(a.rbegin(), a.rend() - m);
  } while (next_permutation(a.begin(), a.end()));
  return 0;
}