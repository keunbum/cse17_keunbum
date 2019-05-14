#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  vector< tuple<int, int, int> > a;
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    a.emplace_back(x, y, r);
  }
  sort(a.begin(), a.end());
  return 0;
}
