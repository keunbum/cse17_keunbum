#include <iostream>
#include <vector>
#include <set>

using namespace std;

int c[3];
set<int> seen;
set<int> ans;

void Rec(int *a) {
  int foo = a[0] + a[1] * 201 + a[2] * 201 * 201;
  if (seen.find(foo) != seen.end()) {
    return;
  }
  seen.insert(foo);
  if (a[0] == 0) {
    ans.insert(a[2]);
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        int b[3];
        for (int i = 0; i < 3; i++) {
          b[i] = a[i];
        }
        int move = min(b[i], c[j] - b[j]);
        b[i] -= move;
        b[j] += move;
        Rec(b);        
      }
    }
  }  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 3; i++) {
    cin >> c[i];
  }
  int a[3];
  a[0] = a[1] = 0;
  a[2] = c[2];
 x Rec(a);
  for (int x : ans) {
    cout << x << ' ';
  }
  return 0;
}
