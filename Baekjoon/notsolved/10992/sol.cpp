#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string a(n - 1, ' ');
  cout << a << '*' << '\n';
  for (int i = 2; i < n; i++) {
    string b(n - i, ' ');
    string c(2 * i - 3, ' ');
    cout << b << '*' << c << '*' << '\n';
  }
  string b(2 * n - 1, '*');
  if (n > 1) cout << b << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}