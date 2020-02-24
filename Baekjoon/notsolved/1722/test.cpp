#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(10, 0);
  for (int i = 10 / 2; i < 10; i++) {
    a[i] = 1;
  }
  do {
    for (int i = 0; i < 10; i++) {
      if (i > 0) cout << ' ';
      cout << a[i];
    }
    cout << '\n';
  } while (next_permutation(a.begin(), a.end()));
  return 0;
}
