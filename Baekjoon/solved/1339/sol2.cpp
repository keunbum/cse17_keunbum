#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  const int alpha = 26;
  vector<long long> cnt(alpha, 0);
  vector<bool> chk(alpha, false);
  while (n--) {
    string s;
    cin >> s;
    int e = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      cnt[(int) (s[i] - 'A')] += e;
      chk[(int) (s[i] - 'A')] = true;
      e *= 10;
    }
  }
  vector<pair<int, int>> a;
  for (int i = 0; i < alpha; i++) { 
    if (chk[i]) {
      a.emplace_back(i, cnt[i]);
    }
  }
  sort(a.begin(), a.end(), [&](const auto& ai, const auto& aj) {
    return ai.second > aj.second;
  });
  int v = 9;
  long long ans = 0;
  for (const auto& x : a) {
    ans += cnt[x.first] * v;
    --v;
  }
  cout << ans << '\n';
  return 0;
}
