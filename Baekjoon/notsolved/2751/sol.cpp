#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int) 1e6;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  quick_sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}