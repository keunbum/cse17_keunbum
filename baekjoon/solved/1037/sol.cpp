#include <iostream>
#include <algorithm>

using namespace std;

int a[50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cout << a[0] * a[n - 1] << '\n';
  return 0;
}