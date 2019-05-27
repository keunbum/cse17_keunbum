#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  long long ans = 0;
  vector<int> fact(n + 1);
  fact[0] = 1;
  for (int i = 0; i < n; i++) {
    fact[i + 1] = fact[i] * (i + 1);
  }
  cout << 
  return 0;
}