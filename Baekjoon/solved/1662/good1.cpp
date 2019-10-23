#include<cstdio>

char s[55];
int d[55], dn;

int main()
{
	int i, j;
	scanf("%s", s);
	for (i = 0; s[i]; i++);
	while (i--)
	{
		if (s[i] == ')') d[++dn] = -1;
		else if (s[i] == '(')
		{
			j = 0;
			while (d[dn] >= 0) j += d[dn--];
			d[dn] = j;
			i--;
			d[dn] *= s[i] - 48;
		}
		else d[++dn] = 1;
	}
	i = 0;
	while (dn) i += d[dn--];
	printf("%d", i);
}
