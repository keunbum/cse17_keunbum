#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a;
  while (getline(cin, a) && a != "END") {
    reverse(a.begin(), a.end());
    cout << a << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
