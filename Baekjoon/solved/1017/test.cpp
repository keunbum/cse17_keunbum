#include <bits/stdc++.h>

using namespace std;

mt19937 rng(time(0));

int main() {
  const int N = 50;
  const int MAX = 1000;
  cout << N << '\n';
  vector<int> a(MAX);
  iota(a.begin(), a.end(), 1);
  shuffle(a.begin(), a.end(), rng);
  for (int i = 0; i < N; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
  return 0;
}
