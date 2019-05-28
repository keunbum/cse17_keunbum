#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int a[8];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  iota(a, a + n, 1);
  set<vector<int>> s;
  for (int t = 0; t < (1 << n); t++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (t & (1 << i)) cnt++;
    }
    if (cnt == m) {
      vector<int> b;
      for (int i = 0; i < n; i++) {
        if (t & (1 << i)) {
          b.push_back(a[i]);
        }
      }
      s.insert(b);
    }
  }
  for (auto it = s.begin(); it != s.end(); it++) {
    for (int i = 0; i < m; i++) {
      cout << (*it)[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}