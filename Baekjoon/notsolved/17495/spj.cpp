#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

/*
BOJ Special Judge (채점 프로그램) 작성 가이드라인
이 프로그램에 있는 주석은 예제 채점 프로그램을 분석하면서 채점 프로그램 작성 요령 및 주의사항을 설명하고 있습니다.
주의: 채점 프로그램은 꼼꼼하게 작성해서 버그 발생 가능성을 최소화해야 합니다.
예를 들어, 제출한 프로그램에 버그가 발생해서 무한 루프에 빠지게 되면
BOJ 채점 큐는 해당 프로그램에 "시간 초과" 딱지를 붙이고 채점을 중단한 뒤 다음 프로그램을 채점하지만
만약 이 채점 프로그램에 버그가 발생해서 무한 루프에 빠지게 되면 
채점 큐는 채점 프로그램이 결과를 낼 때 까지 한없이 기다리게 됩니다.
*/

const int N = 1000;

const int A[7] = {9, 11, 0, 2, 4, 5, 7};
int a[N];

int T(const char* s) {
	return A[s[0] - 'A'] + 12 * (s[1] - '0') + (int) (s[2] == '#');
};

int main(int agrc, char **agrv){
    /* argv[1] 에는 입력 데이터의 파일 이름이 주어집니다. */
    FILE *in = fopen(agrv[1], "r");
    /* argv[2] 에는 "모범 답안"의 파일 이름이 주어집니다. */
    FILE *sol = fopen(agrv[2], "r");
    /* argv[3] 에는 제출한 프로그램의 출력 결과를 가지고 있는 파일 이름이 주어집니다. */
    /* 주의: 이 파일을 읽을 때는 어떠한 가정을 해서도 안됩니다.
       예를 들어, 문제에 "연산을 하는 횟수의 최소값을 출력한다." 라고 되어 있음에도 불구하고
       이 파일에는 정수나 실수, 심지어 문자열이 존재할 수도 있다고 생각하고 채점 프로그램을 작성해야 합니다. */
    FILE *out = fopen(agrv[3], "r");
    char fir[5], sec[5];
    fscanf(in, "%s %s", fir, sec);
    a[0] = T(fir);
    a[1] = T(sec);
    int n;
    /* 입력 (자연수 N) */
    fscanf(in, "%d", &n);
    for (int i = 2; i <= n + 1; i++) {
			char s[5];
			fscanf(in, "%s", s);
			a[i] = T(s);
		}
    fclose(in);
    int ans;
    /* 모범 답안의 첫째 줄 (연산 횟수) */
    /* 모범 답안에는 더 많은 정보가 담겨져 있지만, 채점은 연산 횟수만 사용할 예정입니다.
     *  방법은 모범 답안과 다른 방법이 여러가지가 있을 수 있지만,
       "연산 횟수"는 적어도 모범 답안과 동일해야만 문제에서 요구한 "최소 연산 횟수" 조건을 만족하게 됩니다. */
    fscanf(sol, "%d", &ans);
    fclose(sol);
    int your_ans;
    /* 프로그램 출력 결과의 첫째 줄 (연산 횟수) */
    /* 출력 결과가 올바른지 여부의 검증은 assert(정답이라면 반드시 true 여야 하는 비교문) 을 통해 합니다.
       assert 의 인자가 false 라면, 채점 프로그램은 그 자리에서 종료된 뒤
       채점 큐는 해당 프로그램에 "틀렸습니다" 딱지를 붙입니다.
       assert 의 인자가 true 라면, 채점 프로그램은 계속 진행됩니다. */
    /* 여기서는 "출력 결과에서 정수 1개를 제대로 읽었는가" 에 대해 assert 를 걸고 있습니다.
       앞에서 언급한 것 처럼, 제대로 "정수"가 들어있는지부터 검증해야 합니다. */
    assert(fscanf(out, "%d", &your_ans) == 1);
    /* 출력 결과의 연산 횟수는 모범 답안의 연산 횟수와 동일해야 합니다. (assert) */
    assert(ans == your_ans);
    int your_ans2 = 0;
    int x = 0;
    int y = 1;
    for (int i = 2; i <= n + 1; i++) {
			/* 각 운지법은 정수 1이나 2중 하나여야 한다. (길이 비교도 하기 위해 문자열 포맷으로 비교)*/
			int cur;
			assert(fscanf(out, "%d", &cur) == 1);
			assert(cur == 1 || cur == 2);
			if (cur == 1) {
				your_ans2 += abs(a[i] - a[x]);
				x = i;
			} else {
				your_ans2 += abs(a[i] - a[y]);
				y = i;
			}
		}
		assert(ans == your_ans2);
		int z;
    /* 그 이후 쓰레기 출력이 존재하면 안 됩니다. (assert) */
    assert(fscanf(out, "%d", &z) == -1);
    /* 여기까지 왔다면 제출된 프로그램은 주어진 입력 데이터를 올바로 처리해서 출력했다고 채점한 겁니다.
       main 함수가 0을 반환하면 채점 큐는 (입출력 데이터가 남아있다면) 다음 입출력 데이터를 준비하거나,
       (이번 데이터가 가장 마지막 입출력 데이터였다면) 해당 프로그램에 "맞았습니다!!" 딱지를 붙이게 됩니다. */
    return 0;
}
