#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int go[128];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, e;
  cin >> s >> e;
  int n = (int) s.size();
  int m = (int) e.size();
  int i, j;
  fill_n(go, 128, m);
  for (i = 0; i < m - 1; i++) {
    go[(int) e[i]] = m - i - 1;
  }
  int k = 0, was = 0;
  string ans;
  auto push = [&](int k, int b) {
    for ( ; k < b; k++) {
      ans.push_back(s[k]);
    }
  };
  auto find = [&]() {
    while (i < n) {
      push(k, i + 1);
      k = i + 1;
      j = m - 1;
      while (ans[i - was] == e[j]) {
        if (j == 0) return i;
        i--, j--;
      }
      i += max(go[(int) s[i]], m - j);
    }
    return -1;
  };
  while (true) {
    int t = find();
    if (t == -1) break;
    for (int i = 0; i < m; i++) { ans.pop_back(); was++; }
    i += m;
    k = i;
  }
  push(k, n);
  cout << ((int) ans.size() ? ans : "FRULA" ) << '\n';
  return 0;
}