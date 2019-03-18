#include <iostream>   
#include <ctime>

using namespace std;

int v[31];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d, n;
  cin >> d >> n;
  v[d] = n;
  int i, j;
  for (i = 1; i < n; i++) {
    v[d - 1] = i;
    for (j = d - 2; j >= 1; j--) {
      v[j] = v[j + 2] - v[j + 1];
      if (v[j] <= 0) {
        break;
      }
    }
    if (j == 0 && v[1] <= v[2]) {
      break;
    }
  }
  cout << v[1] << '\n' << v[2] << '\n';
  //cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
