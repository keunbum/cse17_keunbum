#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
vector<int> a1, a2;
vector<pair<int, long long>> a3, a4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
        cout << (a[1] == s ? 1 : 0) << '\n';
        return 0;
    }
    int mi = n >> 1;
    a1.push_back(0);
    for (int i = 1; i <= mi; i++) {
        int t = (int) a1.size();
        for (int j = 0; j < t; j++) {
          a1.push_back(a1[j] + a[i]);
        }
    }
    a2.push_back(0);
    for (int i = mi + 1; i <= n; i++) {
        int t = (int) a2.size();
        for (int j = 0; j < t; j++) {
          a2.push_back(a2[j] + a[i]);
        }
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    int st = 0;
    for (int i = 0; i < (int) a1.size(); i++) {
        if (i + 1 == (int) a1.size() || a1[i + 1] != a1[st]) {
            a3.emplace_back(a1[st], i + 1 - st);
            st = i + 1;
        }
    }
    st = 0;
    for (int i = 0; i < (int) a2.size(); i++) {
        if (i + 1 == (int) a2.size() || a2[i + 1] != a2[st]) {
            a4.emplace_back(a2[st], i + 1 - st);
            st = i + 1;
        }
    }
    long long ans = 0;
    st = 0;
    int en = (int) a4.size() - 1;
    while (st < (int) a3.size() && en >= 0) {
        int foo = a3[st].first + a4[en].first;
        if (foo == s) {
            ans += a3[st].second * a4[en].second;
            st++;
            en--;
        } else
        if (foo > s) en--;
        else st++;
    }
    cout << (s == 0 ? ans - 1 : ans) << '\n';
    return 0;
}
