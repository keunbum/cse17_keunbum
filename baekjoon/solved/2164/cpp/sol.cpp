#include <iostream>
#include <numeric>
#include <deque>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  deque<int> a(n);
  iota(a.begin(), a.end(), 1);
  while (a.size() > 1) {
    a.pop_front();
    int c = a.front();
    a.pop_front();
    a.push_back(c);
  }
  cout << a.front() << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
