#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt[128] = {0, };
  string s;
  while (n--) {
    cin >> s;
    if ((int) s.size() > 0) cnt[s[0]]++;
  }
  bool ok = false;
  for (int i = 0; i < 128; i++) {
    if (cnt[i] >= 5) {
      ok |= true;
      cout << (char) i;
    }
  }
  if (!ok) cout << "PREDAJA";
  return 0;
}