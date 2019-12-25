#include <bits/stdc++.h>

using namespace std;

const int MD = 1000000;

inline int add(int a, int b) {
  a += b;
  if (a >= MD) {
    a -= MD;
  }
  return a;
}

int dp[5001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] >= '1') {
      dp[i + 1] = dp[i];
    }
    int foo = (s[i - 1] - '0') * 10 + s[i] - '0';
    if (i > 0 && foo >= 10 && foo <= 26) {
      dp[i + 1] = add(dp[i + 1], dp[i - 1]);
    }
  }
  cout << dp[n] << '\n';
  return 0;
}
