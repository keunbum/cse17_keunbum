#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "String #" << qq << '\n';
    string foo;
    cin >> foo;
    for (char c : foo) {
      if (c == 'Z') cout << 'A';
      else cout << (char) (c + 1);
    } 
    cout << '\n';
    if (qq < tt) cout << '\n';
  }
  return 0;
}