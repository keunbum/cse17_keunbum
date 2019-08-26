#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4;

int q[N], d[N];
bool was[N], isprime[N];

int RunBfs(string& x, string& y) {
  int b = 0, e = 1;
  int xn = stoi(x);
  int yn = stoi(y);
  q[0] = xn;
  d[xn] = 0;
  was[xn] = true;
  while (b < e) {
    int cn = q[b++];
    if (cn == yn) {
      return d[yn];
    }
    string c = to_string(cn);
    for (int i = 0; i < 4; i++) {
      string t = c;
      for (int j = 0; j < 10; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        t[i] = j + '0';
        int tn = stoi(t);
        if (!was[tn] && isprime[tn]) {
          was[tn] = true;
          d[tn] = d[cn] + 1;
          q[e++] = tn;
        }
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fill_n(isprime, N, true);
  for (int i = 2; i < N; i++) {
    if (!isprime[i]) {
      continue;
    }
    for (int j = i * 2; j < N; j += i) {
      isprime[j] = false;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    fill_n(was, N, false);
    string x, y;
    cin >> x >> y;
    cout << RunBfs(x, y) << '\n';
  }
  return 0;
}
