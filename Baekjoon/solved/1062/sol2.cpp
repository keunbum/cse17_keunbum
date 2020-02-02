#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

const string S = "bdefghjklmopqrsuvwxyz";
const int ALPHA = (int) S.size();

inline int Get(char c) {
  int res = -1;
  for (int i = 0; i < ALPHA; i++) {
    if (c == S[i]) {
      res = i;
      break;
    }
  }
  return res;
}

inline int BC(int bit) {
  int res = 0;
  while (bit > 0) {
    ++res;
    bit = bit & (bit - 1);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k < 5) { cout << 0 << '\n'; return 0; }
  k -= 5;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) {
      int pos = Get(c);
      if (pos != -1) {
        a[i] |= (1 << pos);
      }
    }
  }
  int ans = 0;
  for (int bits = 0; bits < (1 << ALPHA); bits++) {
    if (BC(bits) != k) {
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
