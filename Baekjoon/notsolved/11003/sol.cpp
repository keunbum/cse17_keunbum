#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  deque<int> a;
  int mn = (int) 1e9;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
    mn = min(mn, x);
    if (i >= l) {
      
    }
    cout << mn << '\n';
  }
  return 0;
}
