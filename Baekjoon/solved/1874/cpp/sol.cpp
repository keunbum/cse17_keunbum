#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, v, min = 1;
  vector<int> a, o;
  bool ok = true;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v;
    if (v >= min) {
      for (int j = min; j <= v; j++) {
        a.push_back(j);
        o.push_back('+');
      }
      a.pop_back();
      o.push_back('-');
      min = v + 1;
    } else {
      if (a.back() == v) {
        a.pop_back();
        o.push_back('-');
      } else {
        ok = false;
        break;
      }
    }
  }
  if (!ok) cout << "NO" << '\n';
  else {
    for (int i = 0; i < o.size(); i++)
      cout << (char) o[i] << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
