#include <bits/stdc++.h>

using namespace std;

struct Line {
  int xa;
  int ya;
  int xb;
  int yb;
  Line(a, b, c, d) : xa(a), ya(b) , xb(c), yb(d) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Line> a;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a.emplcae_back(a, b, c, d);
  }

  return 0;
}
