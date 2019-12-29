#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'X') {
        cnt = 0;
      } else {
        cnt++;
      }
      x += (cnt == 2);
    }
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == 'X') {
        cnt = 0;
      } else {
        cnt++;
      }
      y += (cnt == 2);
    }
  }
  cout << x << ' ' << y << '\n';
  return 0;
}
