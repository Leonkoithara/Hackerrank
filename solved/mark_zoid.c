#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mod(int res)
{
	if(res > 0)
		return res;
	else
		return res*-1;
}

int* closest(int posr, int posc, char board[5][5])
{
	int *nxt_block, i, j, min_distance=8, distance;

	nxt_block = (int *)malloc(3*sizeof(int));

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(board[i][j] == 'd')
			{
				distance = mod(i-posr) + mod(j-posc);
				if(min_distance > distance)
				{
					min_distance = distance;
					nxt_block[0] = i;
					nxt_block[1] = j;
				}
			}
		}
	}

	return nxt_block;
}
void next_move(int posr, int posc, char board[5][5]) 
{
	int *p;

	p = closest(posr, posc, board);

	if(posr > p[0])
		printf("UP");
	else if(posr < p[0])
		printf("DOWN");
	else if(posc > p[1])
		printf("LEFT");
	else if(posc < p[1])
		printf("RIGHT");
	else
		printf("CLEAN");
	free(p);
}


int main(void) 
{
    int pos[2], i;
    char board[5][5], line[6];

    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);

    for(i=0; i<5; i++) 
	{
        scanf("%s[^\\n]%*c", line);
        strncpy(board[i], line, 5);
    }

    next_move(pos[0], pos[1], board);
    return 0;
}
