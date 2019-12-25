#include <iostream>

using namespace std;

int a[123456];
int n = 0;

// [s, e]
void up_heap(int s, int e) {
  while (e > 0) {
    int p = (e - 1) / 2;
    if (p < s) return;
    if (a[p] >= a[e]) return;
    swap(a[p], a[e]);
    e = p;
  }
}
  
// [s, e]
void down_heap(int s, int e) {
  while (true) {
    int l = s * 2 + 1;
    int r = l + 1;
    if (l > e) return;
    if (r > e) r = l;
    int max_c = a[l] > a[r] ? l : r;
    if (a[s] >= a[max_c]) return;
    swap(a[s], a[max_c]);
    s = max_c;
  }
}

void add(int x) {
  a[n++] = x;
  up_heap(0, n - 1);
}

void remove() {
  swap(a[0], a[n - 1]);
  n--;
  down_heap(0, n - 1); 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    if (x) add(x);
    else {
      if (n) { cout << a[0] << '\n'; remove(); } 
      else { cout << 0 << '\n'; }
    }
  }
  return 0;
}