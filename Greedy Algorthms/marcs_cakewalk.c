// Marc likes to eat Cakes but he also cares aboutt his health.

#include <stdio.h>
#include<stdlib.h>

int pow(int base,int exponent)
{
	int res;
	while (exponent != 0)
	{
		res *= base;
		-- exponent;
	}
	return res;
}


long int marcsCakewalk(int calorie_size, int* calorie) {
    double dist=0;
    int i=0;
    while(i<(calorie_size-1))
    {
	dist += (pow(2.0,i+1)  * (*(calorie +i)) );	
	i++;
    
    }

    if(i==calorie_size)
    {
	dist += (1 * (*calorie));

    }
    return(dist); 
}



int main() {
    int n; 
    scanf("%i", &n);
    int *calorie = malloc(sizeof(int) * n);
    
    for (int calorie_i = 0; calorie_i < n; calorie_i++) {
       scanf("%i",&calorie[calorie_i]);
    }

    double result = marcsCakewalk(n, calorie);

    printf("%f\n", result);
    return 0;
}

