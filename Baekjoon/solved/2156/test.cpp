#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const int n = 10000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(0));
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << rand() % 1001 << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
