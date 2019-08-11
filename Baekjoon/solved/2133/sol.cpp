#include <iostream>

using namespace std;

int F[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  F[0] = 1;
  for (int i = 2; i <= n; i += 2) {
    F[i] += F[i - 2] * 3;
    for (int j = 0; j <= i - 4; j += 2) {
      F[i] += F[j] * 2;
    }
  }
  cout << F[n] << '\n';
  return 0;
}