#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = (int) 1e5;

int a[MAX_N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int st, en;
  cin >> st >> en;
  a[st] = 1;
  queue<int> que;
  que.push(st);
  while (!que.empty()) {
    int x = que.front();
    cerr << x << '\n';
    que.pop();
    if (x == en) {
      cout << a[en] - 1 << '\n';
      return 0;
    }
    if (x * 2 <= MAX_N && !a[x * 2]) {
      a[x * 2] = a[x];
      que.push(x * 2);
    }
    if (x > 0 && !a[x - 1]) {
      a[x - 1] = a[x] + 1;
      que.push(x - 1);
    }
    if (x < MAX_N && !a[x + 1]) {
      a[x + 1] = a[x] + 1;
      que.push(x + 1);
    }
  }
  return 0;
}