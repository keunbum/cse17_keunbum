#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

int md;

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k >> md;
  const long long MAX = n;
  vector<int> fact(MAX + 1);
  fact[0] = 1;
  for (long long i = 0; i < MAX; i++) {
    fact[i + 1] = (fact[i], (i + 1) % md);
  }

  return 0;
}