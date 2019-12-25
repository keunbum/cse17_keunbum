#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  bool ok = false;
  for (int i = 1; i <= 5; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (int) s.size() - 2; j++) {
      int k;
      for (k = 0; k < 3; k++) {
        if ("FBI"[k] != s[j + k]) break;
      }
      if (k == 3) {
        ok = true;
        cout << i << ' ';
        break;
      }
    }
  }
  if (!ok) cout << "HE GOT AWAY!" << '\n';
  return 0;
} 