#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

pair<int, int> a[567899];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  stable_sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cerr << a[i].second << " - " << i << " = " << a[i].second - i << '\n';
    ans = max(ans, a[i].second - i);
  }
  cout << ans + 1 << '\n';
  cerr << (float) clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}