#include <iostream>

using namespace std;

const int N = (int) 1e6;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int low = 0, high = (int) 1e9;
  for (int t = 0; t < 50; t++) {
    int mid = (low + high) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i] - min(a[i], mid);
    }
    if (sum >= m) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << (low + high) / 2 << '\n';
  return 0;
}