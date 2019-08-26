#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e8;

int S[9];

inline int Cnt(int x) {
  int res = 0;
  while (x > 0) {
    x /= 10;
    res++;
  }
  return res;
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int PO10[9];
  PO10[0] = 1;
  for (int i = 1; i < 9; i++) {
    PO10[i] = PO10[i - 1] * 10;
  }
  S[0] = 0;
  for (int i = 1; i < 9; i++) {
    S[i] = S[i - 1] + i * (PO10[i] - PO10[i - 1]);
  }
  int n;
  cin >> n;
  int cnt = Cnt(n);
  cout << S[cnt - 1] + cnt * (n - PO10[cnt - 1] + 1) << '\n';
//  cerr << (float) clock() / CLOCKS_PER_SEC << " s" << '\n';
  return 0;
}
