#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int alpha =26;
  vector<int> cnt(alpha, 0);
  string s;
  while (getline(cin, s)) {
    for (char c : s) {
      ++cnt[(int) (c - 'a')];
    }
  }
  int mx = *max_element(cnt.begin(), cnt.end());
  for (int i = 0; i < alpha; i++) {
    if (cnt[i] == mx) {
      cout << (char) (i + 'a');
    }
  }
  return 0;
}
