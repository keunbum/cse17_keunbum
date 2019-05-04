#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int L, A, B, a, b;
  cin >> L >> A >> B >> a >> b;
  cout << L - max((A + a - 1) / a, (B + b - 1) / b) << '\n';
  return 0;
}