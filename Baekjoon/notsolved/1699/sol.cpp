#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const int MAX = 100001;

int a[MAX];

void f(int n) {
  int i = (int)sqrt(n);
  for (; i >= 1; i--) {
    if (n == 99225) {
      if (a[n] > a[n - i * i] + 1)
        cout << "i  = " << i << '\n';
    }
    a[n] = min(a[n], a[n - i * i] + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  a[0] = 0;
  for (int i = 1; i < MAX; i++) {
    a[i] = i;
    f(i);
  }
  cout << a[n] << '\n';
//cerr << (float)clock() / CLOCKS_PER_SEC << " seconds" << '\n';
  return 0;
}