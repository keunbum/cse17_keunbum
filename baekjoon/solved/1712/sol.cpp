#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (c <= b) { cout << -1 << '\n'; return 0; }
  cout << (a + c - b) / (c - b) << '\n';
  return 0;
}