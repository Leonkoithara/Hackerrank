#include <iostream>
#include <cstring>

int main()
{
    char source[100], target[100];
    int actions=0, act_limit, i;
    std::cin >> source >> target;
    std::cin >> act_limit;

    int slen = strlen(source);
    int tlen = strlen(target);

    for(i=0;i<slen;i++)
    {
	if(source[i] != target[i])
	    break;
    }

    actions += slen-i;
    actions += tlen-i;

    if(actions == act_limit)
	std::cout << "Yes";
    else if(actions > act_limit)
	std::cout << "No";
    else
    {
	if(!((act_limit-actions)%2))
	    std::cout << "Yes";
	else
	{
	    if(act_limit < slen+tlen)
		std::cout << "No";
	    else
		std::cout << "Yes";
	}
    }

    return 0;
}
