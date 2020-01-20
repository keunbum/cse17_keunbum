#include <cstdio>

int a[11], n;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		int p = 1;
		for(int j=0; j<t; j++){
			while(a[p]) p++;
			p++;
		}
		while(a[p]) p++;
		a[p] = i;
	}
	for(int i=1; i<=n; i++){
		printf("%d ",a[i]);
	}
}