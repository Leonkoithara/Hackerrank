#include <iostream>

int main()
{
	int n, k, q;

	std::cin >> n;
	std::cin >> q;

	int **a = new int*[n];

	for(int i = 0;i < n;i++)
	{
		std::cin  >> k;
		a[i] = new int[k];
		for(int j = 0;j < k;j++)
			std::cin  >> a[i][j];
	}

	int x, y;

	for(int i = 0;i < q;i++)
	{
		std::cin >> x;
		std::cin >> y;
		std::cout << a[x][y] << std::endl;
	}

	return 0;
}
