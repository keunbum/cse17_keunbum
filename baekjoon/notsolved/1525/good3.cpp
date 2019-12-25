#include <cstdio>

int a[9];
int d[362880];
int q[181440], qn;

void add(int x, int y)
{
	if (!d[x])
	{
		d[x] = y;
		q[qn++] = x;
	}
}

int enc()
{
	int i, j, r = 0;
	for (i = 0; i < 9; i++)
	{
		r *= 9 - i;
		for (j = i + 1; j < 9; j++) if (a[i] > a[j]) r++;
	}
	return r;
}

void dec(int x)
{
	int i, j;
	for (i = 8; i >= 0; i--)
	{
		a[i] = x % (9 - i);
		x /= 9 - i;
		for (j = i + 1; j < 9; j++) if (a[i] <= a[j]) a[j]++;
	}
}

int main()
{
	int i, j;
	for (i = 0; i < 9; i++) scanf("%d", a + i);
	add(enc(), 1);
	for (i = 0; i < qn; i++)
	{
		dec(q[i]);
		for (j = 0; j < 9; j++) if (!a[j]) break;
		if (j / 3)
		{
			a[j] = a[j - 3];
			a[j - 3] = 0;
			add(enc(), d[q[i]] + 1);
			a[j - 3] = a[j];
			a[j] = 0;
		}
		if (j / 3 < 2)
		{
			a[j] = a[j + 3];
			a[j + 3] = 0;
			add(enc(), d[q[i]] + 1);
			a[j + 3] = a[j];
			a[j] = 0;
		}
		if (j % 3)
		{
			a[j] = a[j - 1];
			a[j - 1] = 0;
			add(enc(), d[q[i]] + 1);
			a[j - 1] = a[j];
			a[j] = 0;
		}
		if (j % 3 < 2)
		{
			a[j] = a[j + 1];
			a[j + 1] = 0;
			add(enc(), d[q[i]] + 1);
			a[j + 1] = a[j];
			a[j] = 0;
		}
	}
	printf("%d", d[46233] - 1);
}
