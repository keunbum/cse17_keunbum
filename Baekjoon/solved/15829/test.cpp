#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(58);
  cout << 50 << '\n';
  for (int i = 0; i < 50; i++) {
    cout << (char) (rng() % 26 + 'a');
  }
  cout << '\n';
  return 0;
}
