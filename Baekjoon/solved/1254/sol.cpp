#include <bits/stdc++.h>

using namespace std;

bool IsPal(const string& s, string g) {
  int i = 0;
  int j = 0;
  int n = (int) (s.size() + g.size());
  bool res = true;
  int delta = 1;
  while (i < n / 2 && (delta == 1 || j > i)) {
    if (delta == 1 && j == (int) g.size()) {
      delta = -1;
      j = (int) s.size() - 1;
      g = s;
    }
    if (s[i] != g[j]) {
      res = false;
      break;
    }
    ++i;
    j += delta;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  if ((int) s.size() <= 1) {
    cout << s.size() << '\n';
    return 0;
  }
  string g = "";
  int p = 0;
  while (!IsPal(s, g)) {
    g.push_back(s[p]);
    ++p;
  }
  cout << s.size() + g.size() << '\n';
  return 0;
}
