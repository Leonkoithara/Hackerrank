#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

void remove_char(string& s, char c)
{
    for (auto it=s.begin(); it!=s.end(); it++)
	{
        if (*it == c)
            s.erase(it);
    }
}

string encryption(string s)
{
    remove_char(s, ' ');
    int length = s.length();
    int row = floor(sqrt(length)), col = ceil(sqrt(length));
    while (row*col < length)
	{
        if (row == col)
            col++;
        else
            row++;
    }
    std::cout << row << " " << col << std::endl;

    string result;

    for (int i=0; i<col; i++)
	{
        for (int j=0; j<row; j++)
		{
            if (j*col+i < length)
                result += s[j*col+i];
        }
        result += " ";
    }

    std::cout << result << std::endl;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
