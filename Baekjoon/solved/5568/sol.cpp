#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_set<int> s;
  vector<bool> chk(n, false);
  vector<int> v;
  function<void(int)> Dfs = [&](int d) {
    if (d == k) {
      int key = 0;
      for (int e : v) {
        int foo = e / 10 > 0 ? 100 : 10;
        key = key * foo + e;
      }
      s.insert(key);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!chk[i]) {
        chk[i] = true;
        v.push_back(a[i]);
        Dfs(d + 1);
        v.pop_back();
        chk[i] = false;
      }
    }
  };
  Dfs(0);
  cout << s.size() << '\n';
  return 0;
}