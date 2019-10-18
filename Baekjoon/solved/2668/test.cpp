#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

int main(int agrc, char **agrv){
    /* argv[1] 에는 입력 데이터의 파일 이름이 주어집니다. */
    FILE *in = fopen(agrv[1], "r");
    /* argv[2] 에는 "모범 답안"의 파일 이름이 주어집니다. */
    FILE *out = fopen(agrv[2], "r");
    /* argv[3] 에는 제출한 프로그램의 출력 결과를 가지고 있는 파일 이름이 주어집니다. */
    int n;
    fscanf(in, "%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
			fscanf(in, "%d", &a[i]);
		}
    fclose(in);
    int m;
    fscanf(out, "%d", &m);
    bitset<101> A, B;
    for (int i = 0; i < m; i++) {
			int x;
			fscanf(out, "%d", &x);
			A.set(x, 1);
			B.set(a[x], 1);
		}
		assert(A == B);
    fclose(out);
    return 0;
}
