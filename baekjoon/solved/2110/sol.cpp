#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  auto good = [&](int d, int k) {
    int p = 0;
    k--;
    for (int i = 1; i < n && k > 0; i++) {
      if (a[i] - a[p] < d) continue;
      p = i;
      k--;
    }
    return k == 0;
  };
  int low = 1, high = (int) 1e9, mid = 0;
  for (int i = 0; i < 50; i++) {
    mid = (low + high) >> 1;
    //cerr << "low = " << low << " high = " << high << " mid = " << mid << '\n';
    if (good(mid, k)) low = mid;
    else high = mid;
  }
  cout << mid << '\n';
  return 0;
}