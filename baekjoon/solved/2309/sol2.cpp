// The key elements of the sorting algorithm are
// Exchange, Selection, and Insertion.

// Bubble Sort:
//   The exchange is repeated by comparing the order of
//   the two neighboring elements.
//   It's stable because the exchange occur with adjacent elements.

#include <iostream>

using namespace std;

template<typename RandomAccessIterator>
void bubble(RandomAccessIterator first, RandomAccessIterator last) {
  for (auto it = first; it < last - 1; ) {
    auto shift = last - 1; // memo the last swap
    for (auto jt = last - 1; jt > it; jt--) {
      if (*(jt - 1) > *jt) {
        iter_swap(jt, jt - 1);
        shift = jt;
      }
    }
    it = shift;
  }
}

int a[9];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum -= 100;
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (a[i] + a[j] == sum) {
        a[i] = a[j] = 100;
        bubble(a, a + 9);
        for (int k = 0; k < 7; k++) {
          cout << a[k] << '\n';
        }
        return 0;
      }
    }
  }
  return 0;
}