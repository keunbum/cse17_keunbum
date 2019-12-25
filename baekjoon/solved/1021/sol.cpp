#include <iostream>
#include <deque>
#include <numeric>

using namespace std;

deque<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, ans = 0;
  cin >> n >> m;
  a.resize(n);
  iota(a.begin(), a.end(), 1);
  while (m--) {
    int t;
    cin >> t;
    int k;
    for (int i = 0; i < (int) a.size(); i++) {
      if (a[i] == t) {
        k = i;
        break;
      }
    }
    int l = k, r = a.size() - k;
    if (l < r) {
      ans += l;
      while (l--) {
        a.push_back(a.front());
        a.pop_front();
      }
    } else {
      ans += r;
      while (r--) {
        a.push_front(a.back());
        a.pop_back();
      }
    }
    a.pop_front();
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}