#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  int sum = 0, low = ceil(sqrt(m)), high = (int) sqrt(n);
  for (int i = low; i <= high; i++) {
    sum += i * i;
  }
  if (sum) { cout << sum << '\n' << low * low << '\n'; }
  else { cout << "-1" << '\n'; }
  return 0;
}