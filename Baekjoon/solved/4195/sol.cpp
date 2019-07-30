#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <map>

using namespace std;

const int N = (int) 1e5;

int n;
map<string, int> s;
vector<int> p(N), ans(N);

inline int geti(string x) {
  if (s.find(x) == s.end()) {
    s[x] = n++;
  }
  return s[x];
}

int get(int x) {
  return x == p[x] ? x : (p[x] = get(p[x]));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    n = 0;
    iota(p.begin(), p.end(), 0);
    fill(ans.begin(), ans.end(), 1);
    s.clear();
    int m;
    cin >> m;
    while (m--) {
      string f, g;
      cin >> f >> g;
      int x = get(geti(f)), y = get(geti(g));
      if (x != y) {
        p[x] = y;
        ans[y] += ans[x];
      }
      cout << ans[y] << '\n';
    }
  }
  return 0;
}