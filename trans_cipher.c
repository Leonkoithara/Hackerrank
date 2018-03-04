#include <stdio.h>
#include <string.h>

void main()
{
	int i, j, k, l=0, n, max_rows=0, flag=1;
	char cipher[20][20], code[20], temp='A', input[255], output[12][255], buffer[3];

	scanf("%d", &n);

while(n)
{

	scanf("%s", code);
	gets(buffer);
	gets(input);

/*--------remove repeated letters----------*/

	for(i=0;i<strlen(code);i++)
	{
		for(j=i+1;j<strlen(code);j++)
		{
			if(code[i]==code[j])
			{
				for(k=j;k<strlen(code);k++)
					code[k]=code[k+1];
			}
		}
	}
/*---------removal completed---------------*/

/*---------add to cipher-------------------*/

	for(i=0;i<strlen(code);i++)
		cipher[0][i]=code[i];

/*---------add letters--------------------*/

	temp='A';
	for(i=1;temp<='Z';i++)
	{
		max_rows++;
		for(j=0;j<strlen(code) && temp<='Z';j++)
		{
			for(k=0;k<strlen(code);k++)
			{
				if(code[k]==temp)
				{
					flag=0;
					j--;
					break;
				}
			}
			if(flag)
				cipher[i][j]=temp;
			temp++;
			flag=1;
		}
		cipher[i][j]='\0';
	}
	while(j<strlen(code))
	{
		cipher[i-1][j]='\0';
		j++;
	}
	max_rows++;

/*-----------order cipher------------------*/

	for(i=0;i<strlen(code);i++)
	{
		for(j=i+1;j<strlen(code);j++)
		{
			if(cipher[0][i]>cipher[0][j])
			{
				for(k=0;k<max_rows;k++)
				{
					temp=cipher[k][i];
					cipher[k][i]=cipher[k][j];
					cipher[k][j]=temp;
				}
			}
		}
	}

/*------------create output------------------*/

	for(i=0;i<strlen(input);i++)
	{
		temp='A';
		flag=1;

		if(input[i]!=' ')
		{
			for(j=0;j<strlen(code) && flag==1;j++)
			{
				for(k=0;k<max_rows && cipher[k][j]!='\0' && flag==1;k++)
				{
					if(cipher[k][j]==input[i])
					{
						output[l][i]=temp;
						flag=0;
					}
					temp++;
				}	
			}
		}
		else
			output[l][i]=' ';
	}
	output[l][i]='\0';
	l++;
n--;
}
for(i=0;i<=l;i++)
	printf("%s\n", output[i]);
}
