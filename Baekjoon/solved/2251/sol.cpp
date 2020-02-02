#include <iostream>
#include <queue>

using namespace std;

const int MAX = 202;

bool chk[MAX * MAX];
bool ans[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int c[3];
  for (int i = 0; i < 3; i++) {
    cin >> c[i];
  }
  queue<int> q;
  q.push(0);
  chk[0] = true;
  while (!q.empty()) {
    int foo = q.front();
    q.pop();
    int a[3];
    a[0] = foo % MAX;
    a[1] = foo / MAX;
    a[2] = c[2] - a[0] - a[1];
    if (a[0] == 0) {
      ans[a[2]] = true;
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i != j) {
          int b[3];
          for (int k = 0; k < 3; k++) {
            b[k] = a[k];
          }
          int move = min(b[i], c[j] - b[j]);
          b[i] -= move; 
          b[j] += move;
          int bar = b[0] + b[1] * MAX;
          if (!chk[bar]) {
            chk[bar] = true;
            q.push(bar);
          }
        }
      }
    }
  }
  for (int i = 0; i < MAX; i++) {
    if (ans[i]) {
      cout << i << ' ';
    }
  }
  return 0;
}
