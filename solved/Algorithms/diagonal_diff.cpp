#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) 
{
    int sd1 = 0, sd2 = 0, j;

	vector<vector<int>>::size_type rows = arr.size();
    
    for(unsigned int i = 0;i < rows;i++)
	{
		vector<int> row = arr[i];
		vector<int>::size_type col = row.size();
		sd1 += row[i];
		j = col - i - 1;
		sd2 += row[j];
	}

	if(sd1 > sd2)
		return sd1 - sd2;
	else
		return sd2 - sd1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
