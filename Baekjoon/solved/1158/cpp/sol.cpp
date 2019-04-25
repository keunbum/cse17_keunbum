#include <iostream>
#include <numeric>
#include <deque>

using namespace std;

int n, k, p;

inline void add(int &x, int s) {
  x += k;
  x %= s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  deque<int> a(n);
  iota(a.begin(), a.end(), 1);
  p = 0;
  cout << '<';
  for (int i = 0; i < n; i++) {
    p--;
    add(p, a.size());
    cout << a[p];
    if (a.size() != 1) cout << ", ";
    else cout << '>' << '\n';
    a.erase(a.begin() + p);
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
