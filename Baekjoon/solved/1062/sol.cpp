#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline int BC(int bs) {
  int res = 0;
  while (bs > 0) {
    ++res;
    bs = (bs & (bs - 1));
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int alpha = 26;
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) {
      a[i] |= (1 << (c - 'a'));
    }
  }
  int foo = 0;
  for (char c : string("antatica")) {
    foo |= 1 << (c - 'a');
  }
  int ans = 0;
  for (int bits = 0; bits < (1 << alpha); bits++) {
    int bit_cnt = BC(bits);
    if (bit_cnt != k || (bits & foo) != foo) {
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += ((a[i] & bits) == a[i]);
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}
