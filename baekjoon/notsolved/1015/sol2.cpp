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
  int p = 0;
  vector<int> ans(n);
  for(int i = 0; i < n; i++) {
    auto q = min_element(a.begin(), a.end());
    *q = 1234;
    ans[q - a.begin()] = p++;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}