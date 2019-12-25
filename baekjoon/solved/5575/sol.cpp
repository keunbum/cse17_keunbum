#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 3;
  while (tt--) {
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    h2 -= h1;
    m2 -= m1;
    s2 -= s1;
    if (s2 < 0) {
      s2 += 60;
      m2--;
    }
    if (m2 < 0) {
      m2 += 60;
      h2--;
    }
    cout << h2 << ' ' << m2 << ' ' << s2 << '\n';
  }
  return 0;
}