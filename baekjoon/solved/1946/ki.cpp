//왜 틀렸는지 모르겠어요..
#include <iostream>
#include <algorithm>

#define KOO 1000000

using namespace std;

long long score[100001];
int main() {
    int T;
    int n;
    int ans;
    int min;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num1, num2;
            cin >> num1 >> num2;
            score[i] = (long long)num1*KOO+num2;
        }
        sort(score, score + n);
        ans = 0;
        min = 100001;
        for (int i = 0; i < n; i++) {
            //int mn = min;
            if (min > score[i] % KOO) {
                ans++;
                min = score[i] % KOO;
                //cerr << "current min = " << mn << "\t\t";
                //cerr << "score[i] = " << score[i] << "\t\t";
                //cerr << (i) << '\n';
            }
        }
        cout << ans << endl;
    }
    return 0;
}