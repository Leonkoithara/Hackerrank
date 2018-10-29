#include <stdio.h>

void main()
{
	int n, i, tmp, sum, num;

	scanf("%d", &n);

	for(i=1;i<n;i++)
	{
		sum = 0;
		tmp = i;
		num = i;

		while(tmp>0)
		{
			sum = sum + (tmp%10);
			tmp = tmp/10;
		}

		tmp = num;
		while(tmp > 0)
		{
			if(sum * (tmp%10) == num)
			{
				printf("%d\n", num);
				break;
			}
			tmp = tmp/10;
		}
	}
}
