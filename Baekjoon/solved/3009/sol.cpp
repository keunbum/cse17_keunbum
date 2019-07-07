#include <iostream>

using namespace std;

int x[3], y[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
  }
  int a = x[0] ^ x[1] ^ x[2];
  int b = y[0] ^ y[1] ^ y[2];
  cout << a << ' ' << b << '\n';
  return 0;
}