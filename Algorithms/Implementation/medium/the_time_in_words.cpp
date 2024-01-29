#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

std::map<int, string> num_str_map = {
    {1, "one"},        {2, "two"},       {3, "three"},     {4, "four"},
    {5, "five"},       {6, "six"},       {7, "seven"},     {8, "eight"},
    {9, "nine"},       {10, "ten"},      {11, "eleven"},   {12, "twelve"},
    {13, "thirteen"},  {14, "fourteen"}, {15, "fifteen"},  {16, "sixteen"},
    {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
};

std::map<int, string> tens_str_map = {
    {10, "ten"}, {20, "twenty"}, {30, "thirty"}, {40, "fourty"}, {50, "fifty"}};


string num_to_word(int num)
{
    if (num < 20)
	{
        return num_str_map[num];
    }
    else if (num%10 == 0)
	{
        return tens_str_map[num];
    }
    else
    {
        return tens_str_map[num/10*10] + " " + num_str_map[num%10];
    }

    return "Invalid number range";
}

string timeInWords(int h, int m)
{
    string time;

    if (m == 0)
        time = num_str_map[h] + " o' clock";
    else if (m == 15)
        time = "quarter past " + num_str_map[h];
    else if (m == 30)
        time = "half past " + num_str_map[h];
    else if (m == 45)
        time = "quarter to " + num_str_map[h+1];
    else if (m == 1)
        time = "one minute past " + num_str_map[h];
    else if (m == 59)
        time = "one minute to " + num_str_map[h+1];
    else if (m < 30)
        time = num_to_word(m) + " minutes past " + num_str_map[h];
    else if (m > 30)
        time = num_to_word(60-m) + " minutes to " + num_str_map[h+1];

    std::cout << time << std::endl;
    return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
