#include <iostream>

using namespace std;

int a[123][123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int m = 0; m < n; m++) {
    for (int f = 0; f < n; f++) {
      if (!a[f][m]) continue;
      for (int t = 0; t < n; t++) {
        a[f][t] |= a[m][t];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}