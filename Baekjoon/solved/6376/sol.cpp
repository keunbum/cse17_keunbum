#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << "n e\n";
  cout << "- -----------\n";
  cout << "0 1\n";
  cout << "1 2\n";
  cout << "2 2.5\n";
  double acc = 2.5;
  cout << fixed << setprecision(9);
  for (int i = 3, fac = 2; i < 10; i++) {
    fac *= i;
    acc += 1.0 / fac;
    cout << i << ' ' << acc << '\n';
  }
  return 0;
}
