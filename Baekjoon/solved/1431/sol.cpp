#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto Get = [&](const string& s) {
    int res = 0;
    for (char c : s) {
      if (c >= '0' && c <= '9') {
        res += (int) (c - '0');
      }
    }
    return res;
  };
  sort(a.begin(), a.end(), [&](const string& si, const string& sj) {
    if (si.size() != sj.size()) return si.size() < sj.size();
    int sa = Get(si);
    int sb = Get(sj);
    if (sa != sb) return sa < sb;
    for (int i = 0; i < (int) si.size(); i++) {
      if (si[i] != sj[i]) {
        return si[i] < sj[i];
      }
    }
    return false; 
  });
  for (const string& s : a) {
    cout << s << '\n';
  }
  return 0;
}
