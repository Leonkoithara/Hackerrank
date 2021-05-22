#include <iostream>
#include <vector>

using namespace std;

/* print number of apples and oranges that land on house

   s: start point of house
   t: end point of house
   a: apple tree position
   b: orange tree position
   apples: vector of apples' position from tree
   oranges: vector of oranges' position from tree
*/
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges);

int main()
{
	int s, t, a, b, m, n;
	vector<int> apples, oranges;
	cin >> s >> t >> a >> b >> m >> n;
	
	for (int i=0;i<m;i++)
	{
		int temp;
		cin >> temp;
		apples.push_back(temp);
	}
	for (int i=0;i<n;i++)
	{
		int temp;
		cin >> temp;
		oranges.push_back(temp);
	}

	countApplesAndOranges(s, t, a, b, apples, oranges);

	return 0;
}

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
	int apple_count=0, orange_count=0;
	for(auto i=apples.begin();i!=apples.end();i++)
	{
		if(*i+a >= s && *i+a <= t)
			apple_count++;
	}
	cout << apple_count << endl;
	for(auto i=oranges.begin();i!=oranges.end();i++)
	{
		if(*i+b >= s && *i+b <= t)
			orange_count++;
	}
	cout << orange_count << endl;	
}
