#include <iostream>

using namespace std;

const int md = 15746;

inline int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a = 1, b = 2;
  for (int i = 3; i <= n; i++) {
    a = add(a, b);
    swap(a, b);
  }
  cout << b << '\n';
  return 0;
}