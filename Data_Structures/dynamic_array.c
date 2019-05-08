#include <stdio.h>
#include <malloc.h>

int main()
{
	long n, q, i, j, x, y, last_answer=0, *answer;
	long **p, **end, query_type, seq_index, *size, l=0;

	scanf("%ld", &n);
	scanf("%ld", &q);

	p=(long **)malloc(sizeof(long *)*n);
	for(i=0;i<q;i++)
		p[i]=(long *)malloc(sizeof(long)*q);
	end=(long **)malloc(sizeof(long *)*n);
	for(i=0;i<n;i++)
		end[i]=p[i];
	size=(long *)malloc(sizeof(long)*n);
	for(i=0;i<n;i++)
		size[i]=0;
	answer=(long *)malloc(sizeof(long)*q);

	for(i=0;i<n;i++)
		for(j=0;j<q;j++)
			p[i][j]=0;

	for(i=0;i<q;i++)
	{
		scanf("%ld", &query_type);
		scanf("%ld", &x);
		scanf("%ld", &y);

		seq_index=(x^last_answer)%n;

		if(query_type==1)
		{
			*end[seq_index]=y;
			end[seq_index]++;
			size[seq_index]++;
		}
		else
		{
			last_answer=p[seq_index][y%size[seq_index]];
			answer[l]=last_answer;
			l++;
		}
	}
/*
	for(i=0;i<n;i++)
		for(j=0;j<q;j++)
			printf("%ld", p[i][j]);
*/

	for(i=0;i<l;i++)
		printf("%ld\n",answer[i]);

	return 0;
}
