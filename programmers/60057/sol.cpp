#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  auto Len = [&](int x) {
    if (x == 1) {
      return 0;
    }
    int res = 0;
    while (x > 0) {
      ++res;
      x /= 10;
    }
    return res;
  };
  auto IsSame = [&](int sa, int sb, int l) {
    for (int i = 0; i < l; i++) {
      if (s[sa + i] != s[sb + i]) {
        return false;
      }
    }
    return true;
  };
  int n = (int) s.size();
  int ans = n;
  for (int i = 1; i <= n / 2; i++) {
    int cur = 1;
    int len = 0;
    int j;
    for (j = i; j < n; j += i) {
      if (j + i - 1 < n && IsSame(j - i, j, i)) {
        ++cur;
      } else {
        len += Len(cur) + i;
        cur = 1;
      }
//      cerr << "j = " << j << " len = " << len << " cur = " << cur << '\n';
    }
    len += Len(cur) + n - (j - i);
//    cerr << "i = " << i << " len = " << len << '\n';
    ans = min(ans, len);
  }
  return ans;
}