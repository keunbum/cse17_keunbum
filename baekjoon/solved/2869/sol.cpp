#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, v;
  cin >> a >> b >> v;
  cout << (v - b + a - b - 1) / (a - b) << '\n';
  return 0;
}