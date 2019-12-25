#include <iostream>
#include <string>
#include <ctime>
                                                                                   
using namespace std;

class BigInteger {
public:
  int a[123];
  BigInteger() {
    a[0] = 1;
    for (int i = 1; i < 123; i++) a[i] = 0;
  }
  BigInteger operator<<=(int n) {
    while (n--) {
      for (int i = 0; i < 123; i++) a[i] <<= 1;
      for (int i = 0; i < 123; i++) {
        if (a[i] >= 10) {
          a[i] -= 10;
          a[i + 1]++;
        }
      }
    }
    return *this;
  }
};

string to_string(BigInteger &a) {
  string res;
  int i;
  for (i = 122; i >= 0; i--) if (a.a[i]) break;
  for ( ; i >= 0; i--) {
    res += to_string(a.a[i]);
  }
  return res;
}
  

void dfs(int n, int a, int b) {
  if (n == 1) {
    cout << a << ' ' << b << '\n';
    return;
  }
  int c = 6 - a - b;
  dfs(n - 1, a, c);
  cout << a << ' ' << b << '\n';
  dfs(n - 1, c, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  BigInteger a = BigInteger();
  a <<= n;
  a.a[0] -= 1;
  cout << to_string(a) << '\n';
  if (n <= 20) dfs(n, 1, 3);
  //cerr << (float) clock() / CLOCKS_PER_SEC << " s" << '\n';
  return 0;
}