#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  stable_sort(a.begin(), a.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first && a.second > b.second;
  });
  for (int i = 0; i < n; i++) {
    cout << a[i].first << ' ' << a[i].second << '\n';
  }
  return 0;
}