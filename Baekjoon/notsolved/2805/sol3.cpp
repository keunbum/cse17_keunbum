#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n,mp;
    int a[1000005];
    scanf("%d %d",&n,&mp);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int s = 0, e = 1e9;
    while (s != e) {
        int m = (s+e+1)/2;
        int t = mp;
        for (int i=0; i<n; i++) {
            t -= a[i] - min(a[i],m);
            if(t < 0) t = 0;
        }
        if(t <= 0) s = m;
        else e = m-1;
    }
    printf("%d",e);
}