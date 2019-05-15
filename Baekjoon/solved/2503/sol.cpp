#include <iostream>
#include <string>

using namespace std;

bool im[1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string bar;
    int strike, ball;
    cin >> bar >> strike >> ball;
    for (int i = 123; i <= 987; i++) {
      int st = 0, ba = 0;
      string foo = to_string(i);
      if (foo[0] == foo[1] || foo[1] == foo[2] || foo[0] == foo[2]) { im[i] = true; continue; }
      if (foo[1] == '0' || foo[2] == '0') { im[i] = true; continue; }
      for (int j = 0; j < 3; j++) {
        if (foo[j] == bar[j]) st++;
        for (int k = 0; k < 3; k++) {
          if (j == k) continue;
          if (foo[j] == bar[k]) ba++;
        }
      }
      if (strike != st || ball != ba) im[i] = true;
    }
  }
  int ans = 0;
  for (int i = 123; i <= 987; i++) {
    if (!im[i]) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}