#include <stdio.h>
#include <string.h>
#include <math.h>
void nextMove(int n, int r, int c, char grid[101][101])
{
    int i, j;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(grid[i][j] == 'p')
            {
                if(i > r)
                    printf("DOWN");
                else if(i < r)
                    printf("UP");
                else if(j > c)
                    printf("RIGHT");
                else if(j < c)
                    printf("LEFT");
            }
        }
    }
}
int main(void) {

    int n, r, c;

    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &c);

   char grid[101][101];
    
    for(int i=0; i<n; i++) {
        scanf("%s[^\n]%*c", grid[i]);
    }

    nextMove(n, r, c, grid);
    return 0;
}

