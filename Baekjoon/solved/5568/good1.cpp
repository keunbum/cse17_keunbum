#include <stdio.h>
#include <algorithm>
using namespace std;
int N,K;
int A[10],V[10];
int P[10*9*8*7],pcnt;

void back(int cnt, int num)
{
	if(cnt==K) P[pcnt++] = num;
	else
	{
		for(int i=0;i<N;i++)
		{
			if(V[i]==0)
			{
				V[i]=1;
				int n_num = num*10;
				if(A[i]>9) n_num*=10;
				back(cnt+1,n_num+A[i]);
				V[i]=0;
			}
		}
	}
	
}

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",A+i);
		V[i]=0;
	}
	pcnt=0;
	back(0,0);
	sort(P,P+pcnt);
	int ans=0,ex_num=-1;
	for(int i=0;i<pcnt;i++)
	{
		if(ex_num<P[i])
		{
			ans++;
			ex_num = P[i];
		}
	}
	printf("%d",ans);
}