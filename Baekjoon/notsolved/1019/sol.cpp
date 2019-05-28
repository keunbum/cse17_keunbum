#include <iostream>

using namespace std;

const int base = 10;

int ans[base];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  for (int i = 1; i < n; i++) {
    int m = 1;
    for (int j = 1; j < i; j++) {
      m *= j == i - 1 ? base - 1 : base;
    }
    a[0] += m;
    for (int j = 1; j < 2; j++) {
      m = 1;
      for (int k = 1; k < i; k++) {
        m *= base;
      }
      a[j] += m;
    }
  }
  return 0;
}