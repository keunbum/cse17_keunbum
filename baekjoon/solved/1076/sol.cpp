#include <iostream>

using namespace std;

const string a[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long ans = 0;
  string s;
  for (int i = 0; i < 2; i++) {
    cin >> s;
    for (int j = 0; ; j++) {
      if (a[j] == s) {
        ans = ans * 10 + j;
        break;
      }
    }
  }
  cin >> s;
  for (int j = 0; ; j++) {
    if (a[j] == s) break;
    ans *= 10;
  }
  cout << ans << '\n';
  return 0;
}