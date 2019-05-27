#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

char a[15];

inline bool ismo(char c) {
  string s = "aeiou";
  for (char t : s) {
    if (c == t) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, n;
  cin >> l >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  set<string> ans;
  for (int t = 0; t < (1 << n); t++) {
    int mo = 0, ja = 0, cnt = 0;
    string s;
    for (int i = 0; i < n; i++) {
      if (t & (1 << i)) {
        cnt++;
        if (ismo(a[i])) mo++;
        else ja++;
        s.push_back(a[i]);
      }
    }
    if (cnt == l && mo >= 1 && ja >= 2) {
      ans.insert(s);
    }
  }
  for (auto it = ans.begin(); it != ans.end(); it++) {
    cout << (*it) << '\n';
  }
  return 0;
}