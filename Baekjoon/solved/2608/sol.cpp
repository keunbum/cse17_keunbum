#include <iostream>
#include <string>

using namespace std;

const int N = 4001;
const string d[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
const string e[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string f[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const string g[] = { "", "M", "MM", "MMM", "MMMCMC" };

string a[N];

string getr(int); 

inline void init() {
  for (int i = 1; i < N; i++) {
    a[i] = getr(i);
  }
}

string getr(int n) {
  if (n < 10) return d[n];
  if (n < 100) return e[n / 10] + a[n % 10];
  if (n < 1000) return f[n / 100] + a[n % 100];
  return g[n / 1000] + a[n % 1000];
}

inline int getn(string s) {
  for (int i = 1; i < N; i++) {
    if (a[i] == s) return i;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  string foo, bar;
  cin >> foo >> bar;
  int n = getn(foo) + getn(bar);
  cout << n << '\n' << a[n] << '\n';
  return 0;
}