#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int n;
    cin >> n;
    if (!n) { break; }
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> s;
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
      while (!s.empty() && a[s.back()] > a[i]) {
        long long h = a[s.back()];
        s.pop_back();
        int w = i;
        if (!s.empty()) { w = i - s.back() - 1; }
        ans = max(ans, w * h);
      }
      s.push_back(i);
    }
    cout << ans << '\n';
  }
  return 0;
}