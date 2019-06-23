#include <iostream>

using namespace std;

const int N = 1234;

char a[N];
char ans[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> (a + 1);
    for (int j = 1; j <= n; j++) {
      if (a[j] == '.') continue;
      for (int k = 0; k < 8; k++) {
        int x = i + "00011222"[k] - '1';
        int y = j + "01202012"[k] - '1';
        if (ans[x][y] != '*' - '0') {
          ans[x][y] += a[j] - '0';
        }
      }
      ans[i][j] = '*' - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (char) (ans[i][j] > 9 ? 'M' : ans[i][j] + '0');
    }
    cout << '\n';
  }
  return 0;
}