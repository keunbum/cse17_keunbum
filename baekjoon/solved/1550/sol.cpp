#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char c;
  int ans = 0;
  while ((c = cin.get()) != '\n') {
    ans = ans * 16 + (c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10);
  }
  cout << ans << endl;
  return 0;
}