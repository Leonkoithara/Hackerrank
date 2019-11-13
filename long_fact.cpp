#include <bits/stdc++.h>

using namespace std;

char* mul_strs(char *n1, char *n2)
{
    int i, j;
    
    int l1 = strlen(n1), l2=strlen(n2);
    int lx = l1>l2?l1:l2;
    int ly = l1>l2?l2:l1;
    char *res = (char*)malloc((l1+l2)*sizeof(char));
    int computemat[ly][l1+l2];
    bzero(computemat, ly*(l1+l2)*sizeof(int));
    bzero(res, (l1+l2)*sizeof(int));
    char *nl = l1>l2?n1:n2;
    char *ns = l1>l2?n2:n1;

    int prev;
    for(i=0;i<ly;i++)
    {
	prev=0;
	for(j=0;j<lx;j++)
	{
	    int temp = (nl[lx-j-1]-48)*(ns[ly-i-1]-48)+prev;
	    prev = temp/10;
	    computemat[i][i+j] = (temp%10);
	}
	computemat[i][i+j] = prev;
    }

    prev=0;
    for(i=0;i<l1+l2;i++)
    {
	for(j=0;j<ly;j++)
	{
	    res[i] += (computemat[j][i]);
	}
	res[i] += prev;
	prev = res[i]/10;
	res[i] = res[i]%10+48;
    }
    res[i] = prev+48;
    res[i+1] = '\0';

    for(i=0;i<strlen(res)/2;i++)
    {
	char temp=res[i];
	res[i]=res[strlen(res)-i-1];
	res[strlen(res)-i-1]=temp;
    }

    free(n1);
    return res;
}

void extraLongFactorials(int n)
{
    int k=0, t=n;

    while(t)
    {
	t = t/10;
	k++;
    }
    t=n;
    char *n1 = (char*)malloc(k*sizeof(char));
    char *res = (char*)malloc(k*sizeof(char));
    sprintf(res, "%d", 1);

    while(t)
    {
	sprintf(n1, "%d", t);
	res = mul_strs(res, n1);
	t--;
    }

    cout << res;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
