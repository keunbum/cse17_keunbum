#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int e = 10; n > e; e *= 10) {
    n = (int) ((double) n / e + 0.5) * e;
  }
  cout << n << '\n';
  return 0;
}