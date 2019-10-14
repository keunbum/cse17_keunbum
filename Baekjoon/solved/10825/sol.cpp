#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int, string>> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    int x, y, z;
    cin >> s >> x >> y >> z;
    a[i] = {-x, y, -z, s};
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    cout << get<3>(a[i]) << '\n';
  }
  return 0;
}
