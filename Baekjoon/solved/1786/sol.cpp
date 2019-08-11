#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> kmp_table(const string &s) {
  int n = (int) s.size();
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(s[i] == s[k])) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}

vector<int> kmp_search(const string &s, const string &w, const vector<int> &p) {
  int n = (int) s.size();
  int m = (int) w.size();
  assert(n >= 1 && (int) p.size() == n);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < m; i++) {
    while (k > 0 && (k == n || !(w[i] == s[k]))) {
      k = p[k - 1];
    }
    if (w[i] == s[k]) {
      k++;
    }
    if (k == n) {
      res.push_back(i - n + 1);
    }
  }
  return res;
  // returns 0-indexed positions of occurrences of s in w
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string T, P;
  getline(cin, T);
  getline(cin, P);
  vector<int> table = kmp_table(P);
  vector<int> ans = kmp_search(P, T, table);
  int n = (int) ans.size();
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << '\n';
  }
  return 0;
}