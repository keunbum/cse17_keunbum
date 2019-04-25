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
  for (int i = 2; i <= n; i++) {
    string a(n - i, ' ');
    string b(2 * i - 3, ' ');
    cout << a << '*' << b << '*' << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}