#include <iostream>

using namespace std;

int f7[] = {0, 500, 300, 200, 50, 30, 10};
int f17[123], f18[123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cnt = 1;
  for (int i = 1; i <= 6; i++) {
    for (int j = 0; j < i; j++) {
      f17[cnt++] = f7[i];
    }
  }
  cnt = 1;
  for (int i = 1; i <= 5; i++) {
    for (int j = 0; j < 1 << (i - 1); j++) {
      f18[cnt++] = 512 >> (i - 1);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    cout << (f17[a] + f18[b]) * 10000 << '\n';
  }
  return 0;
}
