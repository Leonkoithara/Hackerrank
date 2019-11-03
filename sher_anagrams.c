#include <stdio.h>
#include <string.h>
#include <strings.h>

int main()
{
    char input[100];
    int map[26];

    bzero(map, 26);

    fgets(input, 100);

    for(int i=0;i<strlen(input);i++)
    {
	if(map[input[i]%26] != 0)
	{
	    
	}
	else
	    map[input[i]%26]++;
    }
}
