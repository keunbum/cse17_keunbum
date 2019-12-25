#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = -n + 1; abs(i) < n; i++) {
    int t = abs(i);
    string a(t, ' ');
    string b(2 * n - 1 - 2 * t, '*');
    cout << a + b << '\n';
  } 
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
