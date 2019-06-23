// Cocktail Sort:
//   Advanced of Bubble Sort

#include <iostream>

using namespace std;

template<typename BidirectionalIterator>
void cocktail(BidirectionalIterator first, BidirectionalIterator last) {
  auto shift = first; // memo the last swaped Iterator
  while (first < last) {
    auto it = first;
    while (++it < last) {
      if (*(it - 1) > *it) {
        iter_swap(it - 1, it);
        shift = it;
      }
    }
    last = shift;
    it = last;
    while (--it > first) {
      if (*(it - 1) > *it) {
        iter_swap(it - 1, it);
        shift = it;
      }
    }
    first = shift;
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
        cocktail(a, a + 9);
        for (int k = 0; k < 9 - 2; k++) {
          cout << a[k] << '\n';
        }
        return 0;
      }
    }
  }
  return 0;
}