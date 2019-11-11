#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 1234;
  vector<bool> prime(MAX + 1, true);
  for (int i = 2; i <= MAX; i++) {
    if (prime[i]) {
      for (int j = i + i; j <= MAX; j += i) {
        prime[j] = false;
      }
    }
  }
  string s;
  cin >> s;
  int x = 0;
  for (char c : s) {
    x += (c >= 'A' && c <= 'Z' ? c - 'A' + 27 : c - 'a' + 1);
  }
//  cerr << x << '\n';
  cout << "It is ";
  if (!prime[x]) {
    cout << "not ";
  }
  cout << "a prime word." << '\n';
  return 0;
}
