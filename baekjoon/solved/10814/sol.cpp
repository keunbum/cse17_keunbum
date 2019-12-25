#include <iostream>
#include <algorithm>

using namespace std;

pair<pair<int, int>, string> a[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].second;
    a[i].first.second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i].first.first << ' ' << a[i].second << '\n';
  }
  return 0;
}