#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 123456

#define N_INIT 1
#define N_GROW 2 

typedef struct Vector Vector;

struct Vector {
	int size;
	int capacity;
	int *a;
};

int ans[N];
Vector g[N];

void Add(Vector *v, int x) {
	int *nv = NULL;
	if (v->a == NULL) {
		v->a = (int *) malloc(N_INIT * sizeof(int));
		assert(v->a != NULL);
		v->capacity = N_INIT;
		v->size = 0;
	} else 
	if (v->size >= v->capacity) { // should increase the capacity
		nv = (int *) realloc(v->a, (N_GROW * v->capacity) * sizeof(int));
		assert(nv != NULL);
		v->capacity *= N_GROW;
		v->a = nv;
	}
	v->a[v->size] = x;
	v->size++;
}

void Dfs(int v) {
	int n = g[v].size;
	for (int i = 0; i < n; i++) {
		int u = g[v].a[i];
		if (ans[u] == 0) {
			ans[u] = v;
			Dfs(u);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		Add(&g[x], y);
		Add(&g[y], x);
	}
	ans[1] = 1;
	Dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	for (int i = 1; i <= n; i++) {
		free(g[i].a);
	}
	return 0;
}
