#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string a[50];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = (int) a[0].size();
  for (int i = 0; i < l; i++) {
    char c = a[0][i];
    bool ok = true;
    for (int j = 1; j < n; j++) {
      if (c != a[j][i]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? c : '?');
  }
  return 0;
}