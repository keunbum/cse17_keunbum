#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto sum = [&](int n, int base) {
    int r = 0;
    while (n) {
      cerr << n % base << '\n';
      r += n % base;
      n /= base;
    }
    cerr << r << '\n' << '\n';
    return r;
  };
  for (int i = 2992; i <= 2992; i++) {
    int s1 = sum(i, 10);
    int s2 = sum(i, 12);
    if (s1 != s2) continue;
    int s3 = sum(i, 16);
    if (s2 != s3) continue;
    cout << i << '\n';
  }
  return 0;
}