#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b(m + 1);
  for (int i = 0; i < m; i++) cin >> b[i];
  a[n] = b[m] = (int) 1e9;
  int p_a = 0, p_b = 0;
  while (p_a < n || p_b < m) {
    if (a[p_a] < b[p_b]) {
  	  cout << a[p_a] << ' ';
  	  ++p_a;
    } else {
  	  cout << b[p_b] << ' ';
  	  ++p_b;
    }	
  }
  return 0;
}
