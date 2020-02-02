#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int alpha = 'Z' - 'A' + 1;
  vector<int> cnt(alpha, 0);
  string s;
  cin >> s;
  for (char c : s) {
    ++cnt[c - 'A'];
  }
  bool ok = true;
  int mid = -1;
  for (int i = 0; i < alpha; i++) {
    if (cnt[i] % 2 == 1) {
      if (mid != -1) {
        ok = false;
        break;
      }  
      mid = i;
    }
  }
  if (!ok) {
    cout << "I'm Sorry Hansoo" << '\n';
    return 0;
  }
  string ans;
  for (int i = 0; i < alpha; i++) {
    for (int j = 0; j < cnt[i] / 2; j++) {
      ans += (char) (i + 'A');
    }
  }
  if (mid != -1) {
    ans += (char) (mid + 'A');
  }
  for (int i = alpha - 1; i >= 0; i--) {
    for (int j = 0; j < cnt[i] / 2; j++) {
      ans += (char) (i + 'A');
    }
  }
  cout << ans << '\n';
  return 0;
}
