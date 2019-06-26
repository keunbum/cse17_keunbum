#include <iostream>

using namespace std;

const int md = 9901;

int a[2][123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a[0][0] = 1;
  for (int i = 0; i < 20; i++) {
    a[0][i + 1] = (a[0][i] + a[1][i]) % md;
    a[1][i + 1] = (a[0][i] * 2 +  a[1][i]) % md;
    cerr << (a[0][i + 1] + a[1][i + 1]) % md << '\n';
  }
  cout << (a[0][n] + a[1][n]) % md << '\n';
  return 0;
}