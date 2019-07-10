// Mergesort is a stable sort.

#include <iostream>

using namespace std;

const int N = (int) 1e6;

int a[N];
int buf[N];

// [first, middle) ~ [middle, last)
template <typename RandomAccessIterator>
void merge(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last) {
  int la = (int) (middle - first);
  int lb = (int) (last - middle);
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < la) {
    *(buf + j++) = *(first + i++);
  }
  i = 0;
  j = 0;
  while (i < lb && j < la) {
    *(first + k++) = *(buf + j) < *(middle + i) ? *(buf + j++) : *(middle + i++);
  }
  while (j < la) {
    *(first + k++) = *(buf + j++);
  }
}

// [first, last)
template <typename RandomAccessIterator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last) {
  int n = (int) (last - first);
  if (n <= 1) return;
  RandomAccessIterator middle = first + n / 2;
  merge_sort(first, middle);
  merge_sort(middle, last);
  merge(first, middle, last);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  merge_sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}