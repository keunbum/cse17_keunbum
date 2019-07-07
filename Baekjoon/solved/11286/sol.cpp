#include <iostream>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(const int &a, const int &b) const {
    if (abs(a) != abs(b)) return abs(a) > abs(b);
    return a > b;
  }  
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  priority_queue<int, vector<int>, cmp> s;
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    if (x != 0) {
      s.push(x);
    } else {
      if (s.empty()) {
        cout << 0 << '\n';
      } else {
        cout << s.top() << '\n';
        s.pop();
      }
    }
  }
  return 0;
}