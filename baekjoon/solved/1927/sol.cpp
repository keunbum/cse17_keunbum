#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  priority_queue<int, vector<int>, greater<int>> s;
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    if (x) {
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