#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *arr, n, r, *ptr;

    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    scanf("%d", &r);

    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    ptr = arr;

    ptr += r%n;

    for(int i=0;i<n;i++)
    {
        printf("%d ", *ptr);
        if(ptr == arr+n-1)
            ptr = arr;
        else
            ptr++;
    }

    return 0;
}

