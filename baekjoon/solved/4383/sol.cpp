#include <iostream>

using namespace std;

const int N = 3456;

bool chk[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    int p;
    cin >> p;
    fill_n(chk, N, false);
    bool ok = true;
    for (int i = 1; i < n; i++) {
      int c;
      cin >> c;
      int d = abs(c - p);
      if (d <= 0 || d >= n || chk[d]) {
        ok = false;
        break;
      }
      chk[d] = true;
      p = c;
    }
    cout << (ok ? "Jolly" : "Not jolly") << '\n';
    string s;
    getline(cin, s);
  }
  return 0;
}