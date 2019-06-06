#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

int a[123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  istringstream sin(s);
  int tt;
  sin >> tt;
  while (tt--) {
    getline(cin, s);
    istringstream sin(s);
    int ans = 0;
    int i = 0;
    while (sin >> a[i]) {
      for (int j = 0; j < i; j++) {
        ans = max(ans, __gcd(a[j], a[i]));
      }
      i++;
    }
    cout << ans << '\n';
  }
  //cerr << (float) clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}