/* Note this program assumes different input (x,y) instead of (y,x)
   as in case of the Hackerrank problem please keep this in mind
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	vector<vector<int>> x;
	vector<vector<int>> y;
	vector<vector<int>> d1;
	vector<vector<int>> d2;
} real_obstacles;

/*
 This function returns the number of squares a queen can attack given obstacles

 n: # rows and columns in chessboard
 k: # obstacles
 r_q: queen row position
 c_q: queen column position
 obstacles: vector of pairs of ints giving obstacle position
 */
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles);

/*
 This function returns 4 vectors with obstackles in line of attack of queen.
 The four vectors are: x, y, d1, d2
 x: in lateral view(qx = ox)
 y: in longitudal view(qy = oy)
 d1: in negative diagonal(qx-qy = ox-oy)
 d2: in positive diagonal(qx+qy = ox+oy)
*/
real_obstacles get_obstacles(vector<vector<int>> &obstacles, int n, int qx, int qy)
{
	real_obstacles all_obstacles;

	for(int i=0;i<n;i++)
	{
		int ox = obstacles[i][0], oy = obstacles[i][1];
		if(ox == qx)
			all_obstacles.x.push_back(obstacles[i]);
		else if(oy == qy)
			all_obstacles.y.push_back(obstacles[i]);
		else if(ox+oy == qx+qy)
			all_obstacles.d2.push_back(obstacles[i]);
		else if(ox-oy == qx-qy)
			all_obstacles.d1.push_back(obstacles[i]);
	}

	return all_obstacles;
}

void print_vec(vector<vector<int>> v)
{
	for(auto x=v.begin();x!=v.end();x++)
	{
		cout << (*x)[0] << "," << (*x)[1] << " ";
	}
	cout << endl;
}


int main()
{
	int n, k, qx, qy;
	cout << "board_size, #obstacles, qx, qy: ";
	cin >> n >> k >> qx >> qy;
	vector<vector<int>> obstacles;
	for(int i=0;i<k;i++)
	{
		int x, y;
		cout << "Obstacle #" << i << ": ";
		cin >> x >> y;
		vector<int> point;
		point.push_back(x);point.push_back(y);
		
		obstacles.push_back(point);
	}
	int output = queensAttack(n, k, qx, qy, obstacles);
	return 0;
}

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
	real_obstacles r_obs = get_obstacles(obstacles, k, r_q, c_q);
	print_vec(r_obs.x);
	print_vec(r_obs.y);
	print_vec(r_obs.d1);
	print_vec(r_obs.d2);

	int attack_squares = 2*(n-1)
		               + (n-(r_q > c_q ? r_q-c_q : c_q-r_q)-1)
		               + (n-(r_q+c_q > n+1 ? r_q+c_q-n-1 : n+1-r_q-c_q)-1);

	int t1=0, t2=n+1;
	for(auto xi = r_obs.x.begin();xi != r_obs.x.end();xi++)
	{
		if((*xi)[1] > c_q && (*xi)[1] < t2)
			t2 = (*xi)[1];
		if((*xi)[1] < c_q && (*xi)[1] > t1)
			t1 = (*xi)[1];
	}
	attack_squares -= t1;
	attack_squares -= n + 1 - t2;
	cout << t1 << t2 << " " << attack_squares << endl;

	t1 = 0, t2=n+1;
	for(auto yi = r_obs.y.begin();yi != r_obs.y.end();yi++)
	{
		if((*yi)[0] > r_q && (*yi)[0] < t2)
			t2 = (*yi)[0];
		if((*yi)[0] < r_q && (*yi)[0] > t1)
			t1 = (*yi)[0];		
	}
	attack_squares -= t1;
	attack_squares -= n - t2 + 1;
	cout << t1 << t2 << " " << attack_squares << endl;

	int x=n+1, y=0;
	t1 = 0, t2=n+1;
	for(auto d1i = r_obs.d1.begin();d1i != r_obs.d1.end();d1i++)
	{
		if((*d1i)[0] > r_q && (*d1i)[1] < t2)
		{
			x = (*d1i)[0] < (*d1i)[1] ? (*d1i)[1] : (*d1i)[0];
			t2 = (*d1i)[1];
		}
		if((*d1i)[0] < r_q && (*d1i)[1] > t1)
		{
			y = (*d1i)[0] > (*d1i)[1] ? (*d1i)[1] : (*d1i)[0];
			t1 = (*d1i)[1];
		}
	}
	attack_squares -= n - x + 1;
	attack_squares -= y;
	cout << t1 << t2 << " " << attack_squares << endl;

	x = 0, y = 0;
	t1=0, t2=n+1;
	for(auto d2i = r_obs.d2.begin();d2i != r_obs.d2.end();d2i++)
	{
		if((*d2i)[0] < r_q && (*d2i)[1] < t2)
		{
			y = (*d2i)[0] < n + 1 - (*d2i)[1] ? (*d2i)[0] : n + 1 - (*d2i)[1];
			t2 = (*d2i)[1];
		}
		if((*d2i)[0] > r_q && (*d2i)[1] > t1)
		{
			x = (*d2i)[0] < n + 1 - (*d2i)[1] ? (*d2i)[1] : n + 1 - (*d2i)[0];
			t1 = (*d2i)[1];
		}
	}
	attack_squares -= x;
	attack_squares -= y;
	cout << t1 << t2 << " " << attack_squares << endl;		

	return attack_squares;
}
