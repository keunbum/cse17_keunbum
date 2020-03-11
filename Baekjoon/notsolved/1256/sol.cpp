#include <bits/stdc++.h>

using namespace std;

char s[210];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) s[i] = 'a';
  for (int i = n; i < n + m; i++) s[i] = 'z';
  s[n + m] = 0;
  do {
    cout << s << '\n';
  } while (next_permutation(s, s + n + m));
  return 0;
}
