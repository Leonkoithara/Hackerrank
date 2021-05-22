#include <functional>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

string biggerIsGreater(string w);

int main()
{
	int n;
	string word;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> word;
		cout << biggerIsGreater(word) << endl;
	}
	return 0;
}

string biggerIsGreater(string w)
{
	bool found=false;
    string no_ans = "no answer";
	auto x=w.rbegin();
	auto y=w.rbegin();
	
    for(auto i=w.rbegin();i!=w.rend();i++)
    {
        for(auto j=i+1;j!=w.rend();j++)
        {
            if(*i > *j)
            {
				if(!found)
				{
					x = i;
					y = j;
					found = true;
				}
				else
				{
					if( distance(y, w.rbegin()) < distance(j, w.rbegin()) )
					{
						x = i;
						y = j;					
					}		
				}
            }
        }
    }

	if(found)
	{
		cout << *x << *y << endl;
		swap(*x, *y);
		sort(w.rbegin(), y, greater<char>());		
		return w;
	}

    return no_ans;
}
