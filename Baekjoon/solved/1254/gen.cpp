#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(58);
  int N = 1000;
  while (N--) {
    char ch = rng() % 26 + 'a';
    cout << ch;
  }
  cout << '\n';
  return 0;
}
