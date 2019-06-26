#include <iostream>
#include <vector>

using namespace std;

// Segment Tree
class segtree {
public:
  struct node {
    long long value;
    void apply(int l, int r, long long v) {
      value = v;
    }
  };
  node unite(const node &a, const node &b) const {
    node res;
    res.value = a.value + b.value;
    return res;
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;
  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    //pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = (int) v.size();
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    return get(0, 0, n - 1, ll, rr);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    modify(0, 0, n - 1, ll, rr, v...);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  segtree st(a);
  m += k;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      b--;
      st.modify(b, b, c); 
    } else {
      b--; c--;
      if (b > c) swap(b, c);
      cout << st.get(b, c).value << '\n';
    }
  }
  return 0;
}