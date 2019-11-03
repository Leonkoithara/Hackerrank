#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b)
{
    return a>b?a-b:b-a;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) 
{
    int c1=0, c2=0, c3=0, c4=0, min=0;
    int arr[3][3] = {4, 9, 2, 
                     3, 5, 7, 
                     8, 1, 6};
    int rarr[3][3] = {2, 9, 4, 
                     7, 5, 3, 
                     6, 1, 8};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c1 += mod(arr[i][j], s[i][j]);
            c2 += mod(arr[2-j][i], s[i][j]);
            c3 += mod(arr[2-i][2-j], s[i][j]);
            c4 += mod(arr[j][2-i], s[i][j]);
        }
        cout << "\n";
    }
    int t;
    t = c1>c2?c2:c1;
    min = c3>c4?c4:c3;
    min = min>t?t:min;

    c1=0, c2=0, c3=0, c4=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c1 += mod(rarr[i][j], s[i][j]);
            c2 += mod(rarr[2-j][i], s[i][j]);
            c3 += mod(rarr[2-i][2-j], s[i][j]);
            c4 += mod(rarr[j][2-i], s[i][j]);
        }
    }

    t = c1>c2?c2:c1;
    min = t>min?min:t;
    t = c3>c4?c4:c3;
    min = t>min?min:t;

    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
