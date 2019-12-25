#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = N;
    *lower_bound(a, a + i, x) = x;
  }
  cout << (int) (lower_bound(a, a + n, N) - a)  << '\n';
  return 0;
}
