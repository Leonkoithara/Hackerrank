#include <iostream>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2)
{
	int x = x1-x2, v = v2-v1;
	string yes="YES", no="NO";

	if(v==0)
	{
		if(x == 0)
			return yes;
		else
			return no;
	}
	if(!(x%v) && x/v > 0)
		return yes;
	else
		return no;
}

int main()
{
	int x1, v1, x2, v2;
	cin >> x1 >> v1 >> x2 >> v2;
	cout << kangaroo(x1, v1, x2, v2);
	return 0;
}
