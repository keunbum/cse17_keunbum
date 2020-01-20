#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  do {
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (v[j] > v[i]) {
          ++b[v[i]];
        }
      }
    }
    if (b == a) {
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << v[i] + 1;
  }
  cout << '\n';
  return 0;
}
