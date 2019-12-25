#include <stdio.h>
#include <stdlib.h>

#define N 123456

typedef struct Node Node;

struct Node {
  int x;
  Node *next;
};

int ans[N];
Node g[N];

Node *new_node(int x) {
  Node *res = (Node *) malloc(sizeof(Node));
  res->x = x;
  res->next = NULL;
  return res;
}

Node *add(Node *head, int x) {
  if (head == NULL) {
    return head = new_node(x);
  }
  Node *p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = new_node(x);
  return head; 
}

Node *remove_head(Node *head) {
  Node *cur = head;
  head = head->next;
  free(cur);
  return head;
}

void dfs(int v) {
  for (Node *p = g[v].next; p != NULL; p = p->next) {
    int u = p->x;
    if (ans[u] == 0) {
      ans[u] = v;
      dfs(u);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].next = add(g[x].next, y);
    g[y].next = add(g[y].next, x);
  }
  ans[1] = 1;
  dfs(1);
  for (int i = 2; i <= n; i++) {
    printf("%d\n", ans[i]);
  }
  for (int i = 1; i <= n; i++) {
    while (g[i].next != NULL) {
      g[i].next = remove_head(g[i].next);
    }
  }
  return 0;
}