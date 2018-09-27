#include <stdio.h>
#include <stdlib.h>

int mod(int res)
{
	if(res > 0)
		return res;
	else
		return res*-1;
}

void next_move(int, int, char [5][5]);
int* closest(int, int, char [5][5]);

int main(void) 
{
    int pos[2], i;
    char board[5][5];

    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);

    for(i=0; i<5; i++) 
	{
        scanf("%s[^\\n]%*c", board[i]);
    }

    next_move(pos[0], pos[1], board);
    return 0;
}

int* closest(int posr, int posc, char board[5][5])
{
	FILE *append;
	int *nxt_block, i, j, min_distance=8, distance, x=1, y=1;

	append = fopen("file.txt", "a+");
	nxt_block = (int *)malloc(3*sizeof(int));

	nxt_block[0] = -1;
	nxt_block[1] = -1;

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(board[i][j] == 'd')
			{
				fputc(i, append);
				fputc(j, append);
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

	fseek(append, 0, SEEK_SET);

	if(nxt_block[0] == -1)
	{
		return (int *)0;
		fclose(append);
	}
	else
	{
		while(y != EOF)
		{
			x = fgetc(append);
			y = fgetc(append);

			if(x == nxt_block[0] && y == nxt_block[1])
			{
				fputc(9, append);
			}
		}
		fclose(append);
		return nxt_block;
	}
}


void next_move(int posr, int posc, char board[5][5]) 
{
	int *p;

	p = closest(posr, posc, board);

	if(p != 0)
	{
		if(posr > p[0])
			printf("UP");
		else if(posr < p[0])
			printf("DOWN");
		else if(posc > p[1])
			printf("LEFT");
		else if(posc < p[1])
			printf("RIGHT");
		else if(posr==p[0] && posc==p[1])
			printf("CLEAN");
	}
	else
	{
		wander(posr, posc, board);
	}

	free(p);
}
