#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int) 2e6;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) {
    cin >> a[i];
  }
  inplace_merge(a, a + n, a + n + m);
  for (int i = 0; i < n + m; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}