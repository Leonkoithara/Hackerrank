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

int closest_ckpt(int, int, char [5][5]);
int* closest(int, int, char [5][5]);
void wander(int, int, char [5][5]);
void next_move(int, int, char [5][5]);

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

int closest_ckpt(int posr, int posc, char board[5][5])
{
	int i, min_distance=8, distance, x, y, res, checked[4];

	for(i=0;i<4;i++)
	{
		x = 2*(i/2)+1;
		y = 2*(i%2)+1;

		distance = mod(x-posc)+mod(y-posr);

		if(min_distance > distance)
		{
			min_distance = distance;
			res = i;
		}
	}

	return res;
}

int* closest(int posr, int posc, char board[5][5])
{
	int *nxt_block, i, j, min_distance=8, distance;

	nxt_block = (int *)malloc(3*sizeof(int));

	nxt_block[0] = -1;
	nxt_block[1] = -1;

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

	if(nxt_block[0] == -1)
		return (int *)0;

	return nxt_block;
}

void wander(int posr, int posc, char board[5][5])
{
	int *p, i, ckpt;

	if(posr < 1 || posr > 3 || posc < 1 || posc > 3 || (posc == posr && posc == 2))
	{
		ckpt = closest_ckpt(posr, posc, board);

		if(posr > 2*(ckpt%2)+1)
			printf("UP");
		else if(posr < 2*(ckpt%2)+1)
			printf("DOWN");
		else if(posc > 2*(ckpt/2)+1)
			printf("LEFT");
		else if(posc < 2*(ckpt/2)+1)
			printf("RIGHT");
	}

	else
	{
		if(posr == 1 && posc != 3)
			printf("RIGHT");
		else if(posr == 3 && posc != 1)
			printf("LEFT");
		else if(posc == 3 && posr != 3)
			printf("DOWN");
		else
			printf("UP");
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
