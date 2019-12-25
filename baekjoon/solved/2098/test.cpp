#include <iostream>
#include <ctime>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(0));
  int n = 16;
  int v = (int) 1e6;
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) cout << ' ';
      cout << (i == j ? 0 : (rand() % v));
    }
    cout << '\n';
  }
  return 0;
}