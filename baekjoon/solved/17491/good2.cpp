#include <bits/stdc++.h>
using namespace std;

int N, A[22][22], D[18][252525], X[22], Y[22];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d %d", X+i, Y+i);
    for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) A[i][j] = A[j][i] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
    for(int i=1; i<=N; i++) for(int j=0; j<1<<N; j++) D[i][j] = 1e9;
    for(int i=1; i<=N; i++) D[i][1<<(i-1)] = abs(X[i]) + abs(Y[i]);
    for(int i=1; i<1<<N; i++) for(int j=0; j<N; j++) if(i & (1 << j)) {
        for(int k=0; k<N; k++) if(!((1 << k) & i)) D[k+1][i|(1<<k)] = min(D[k+1][i|(1<<k)], D[j+1][i] + A[j+1][k+1]);
    }
    int ans = 1e9;
    for(int i=1; i<=N; i++) ans = min(ans, D[i][(1<<N)-1] + abs(X[i]) + abs(Y[i]));
    printf("%d\n", ans);
}
