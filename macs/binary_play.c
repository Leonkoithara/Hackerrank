#include <stdio.h>
#include <string.h>
#include <math.h>

int to_int(char a[])
{
	int tmp, i;

	tmp = 0;
	for(i=strlen(a)-1;i>=0;i--)
	{
		if(a[i] == '1')
		{
			tmp = tmp + pow(2, strlen(a)-i-1);
		}
	}

	return tmp;
}

int main()
{
	int A, B, q, i, change;
	char a[24], b[24];

	gets(a);
	gets(b);

	A = to_int(a);
	B = to_int(b);

	scanf("%d", &q);

	for(i=0;i<q;i++)
	{
		scanf("%d", &change);
		b[change-1] = '1';

		B = to_int(b);

		if(A > B)
			printf("YES\n");
		else if(A < B)
			printf("NO\n");
		else
			printf("-1\n");
	}

	return 0;
}
