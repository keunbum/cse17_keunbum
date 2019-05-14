#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Segment Tree
class Tree {
public:
  vector<long long> a; // Origin array
  vector<long long> tree; // Index tree
  Tree() { }
  Tree(int n) {
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];               
    }                            
    int h = (int) ceil(log2(n));
    tree.resize(1 << (h + 1));
  }
  // node: Index in tree starting from 1
  long long foo(int node, int s, int e) {
    if (s == e) { // Leaf node
      return tree[node] = a[s];
    } else { // Store the sum of left and right child
      return tree[node] = foo(node * 2, s, (s + e) / 2) + foo(node * 2 + 1, (s + e) / 2 + 1, e);
    } 
  }
  // Sum from l to r
  long long sum(int node, int s, int e, int l, int r) {
    if (l > e || r < s) { return 0; } // There's no need to explore
    if (l <= s && e <= r) { return tree[node]; }
    return sum(node * 2, s, (s + e) / 2, l, r) + sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
  }
  void bar(int node, int s, int e, int idx, long long diff) {
    if (idx < s || idx > e) return; // Out of range
    tree[node] += diff;
    if (s != e) {
      bar(node * 2, s, (s + e) / 2, idx, diff);
      bar(node * 2 + 1, (s + e) / 2 + 1, e, idx, diff);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  Tree tr(n);
  tr.foo(1, 0, n - 1);
  m += k;
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      long long c;
      cin >> c;
      b--;
      long long diff = c - tr.a[b];
      tr.a[b] = c;
      tr.bar(1, 0, n - 1, b, diff);
    } else {
      int c;
      cin >> c;
      cout << tr.sum(1, 0, n - 1, b - 1, c - 1) << '\n';
    }
  }
  return 0;
}