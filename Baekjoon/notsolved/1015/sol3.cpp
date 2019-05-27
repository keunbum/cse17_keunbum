#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> d[1234];
  for (int i = n - 1; i >= 0; i--) {
    d[a[i]].push_back(i);
  }
  sort(a.begin(), a.end());
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int t = d[a[i]].back();
    ans[t] = i;
    d[a[i]].pop_back();
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}