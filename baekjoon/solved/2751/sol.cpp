#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int) 1e6;

int a[N];

// [first, last)
template <typename RandomAccessIterator>
RandomAccessIterator partition(RandomAccessIterator first, RandomAccessIterator last) {
  auto middle = ((int) (last - first)) / 2;
  auto pivot = *(first + middle);
  while (true) {
    while (*(first) < pivot) first++;
    while (*(last - 1) > pivot) last--;
    if (first >= last - 1) {
      return first;
    }
    iter_swap(first, last - 1);
    first++;
    last--;
  }
}

// [first, last)
template <typename RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last) {
  if (first >= last - 1) return;
  auto pivot = partition(first, last);
  quick_sort(first, pivot);
  quick_sort(pivot, last);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  quick_sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}