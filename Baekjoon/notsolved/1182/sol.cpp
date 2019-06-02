#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[21], n;
vector<int> v1, v2;

int cnt(vector<int> &v, int x) {
    return (int) (upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x));
}

void dfs(int pos, int e, int c, vector<int> &v) {
    if (pos == e){
        v.push_back(c);
    } else {
        dfs(pos + 1, e, c + a[pos], v);
        dfs(pos + 1, e, c, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, n / 2, 0, v1);
    dfs(n / 2, n, 0, v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    long long ret = 0;
    for (auto &i : v1) {
        ret += cnt(v2, c - i);
    }
    cout << (c == 0 ? ret - 1 : ret) << '\n';
    cout << ret << '\n';
}