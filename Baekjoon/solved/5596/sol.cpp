#include <iostream>

using namespace std;

int a, b, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 4; i++) {
    cin >> t;
    a += t;
  }
  for (int i = 0; i < 4; i++) {
    cin >> t;
    b += t;
  }
  cout << max(a, b) << '\n';
  return 0;
}