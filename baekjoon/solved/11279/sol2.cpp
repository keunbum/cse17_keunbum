#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a;
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    if (x) {
      a.push_back(x);
      push_heap(a.begin(), a.end());
    } else {
      if (a.size()) {
        cout << a[0] << '\n';
        pop_heap(a.begin(), a.end());
        a.pop_back();
      } else {
        cout << 0 << '\n';
      } 
    }
  }
  return 0;
}