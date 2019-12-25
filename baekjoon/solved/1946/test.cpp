#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  int n = 100000;
  cout << tt << '\n';
  cout << n << '\n';
  vector<int> a(n);
  iota(a.begin(), a.end(), 0);
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle (a.begin(), a.end(), std::default_random_engine(seed));
  for (int i = 0; i < n; i++) {
    cout << (i + 1) << ' ' << a[i] + 1 << '\n';
  }
  return 0;
}