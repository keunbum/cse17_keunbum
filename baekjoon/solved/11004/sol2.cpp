// Heapsort is a comparison-based algorithm.
// It is an in-place algorithm, but not a stable sort.

// when child's index = c,
// parent's index = (c - 1) / 2

#include <iostream>
#include <algorithm>
                                              
using namespace std;

const int N = (int) 5e6;

int a[N];                             

// [start, end]
template <typename RandomAccessIterator>
void downheap(RandomAccessIterator first, int start, int end) {
  int p = start;
  while (true) {
    int l = p * 2 + 1;
    int r = l + 1;
    if (l > end) return;
    if (r > end) r = l;
    int max_c = *(first + l) > *(first + r) ? l : r;
    if (*(first + p) >= *(first + max_c)) {
      return;
    }
    iter_swap(first + p, first + max_c);
    p = max_c;
  }
}

// [first, last)
template <typename RandomAccessIterator>
void heapsort(RandomAccessIterator first, RandomAccessIterator last) {
  int n = (int) (last - first);
  for (int i = (n - 1) / 2; i >= 0; i--) {
    downheap(first, i, n - 1);
  }
  for (int i = n - 1; i > 0; i--) {
    iter_swap(first, first + i);
    downheap(first, 0, i - 1);
  } 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  heapsort(a, a + n);
  cout << a[k - 1] << '\n';
  return 0;
}