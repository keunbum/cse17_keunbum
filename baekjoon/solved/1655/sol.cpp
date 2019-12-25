#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> a;
priority_queue<int, vector<int>, greater<int>> b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int x;
  cin >> x;
  cout << x << '\n';
  int p = 1;
  while (--tt) {
    int y;
    cin >> y;
    p ^= 1;
    if (x <= y) {
      b.push(y);
      if (p) {
        a.push(x);
        x = b.top();
        b.pop();
      }
    } else {
      a.push(y);
      if (!p) {
        b.push(x);
        x = a.top();
        a.pop();
      }
    }
    cout << x << '\n';  
  }
  return 0;
}