#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  int k, query;
  cin >> n >> k >> q;
  
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << GetDis(x, y) << '\n';
  }
  return 0;
}
