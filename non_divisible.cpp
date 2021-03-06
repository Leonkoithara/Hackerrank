#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int nonDivisibleSubset(int k, vector<int> s)
{
    int rem[k/2+1][2], res=0;
    memset(rem, 0, ((k/2+1)*2)*sizeof(int));

    for(int i=0;i<s.size();i++)
    {
	int t = s[i]%k;
	if (t <= k/2)
	    rem[t][0]++;
	else
	    rem[k-t][1]++;
    }

    for (int i=0; i<=k/2; ++i)
    {
	if(((i == k/2 && !(k%2)) || i==0) && rem[i][0] > 0)
	    res++;
	else if(rem[i][0] > rem[i][1])
	    res += rem[i][0];
	else if(rem[i][0] < rem[i][1])
	    res += rem[i][1];
    }

    cout << res << "\n";
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
