#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int k = 4;
	int max = -1;
	vector<int> A = {0,0, 5,-2,6,-1,9,-3,8,-1,10,-1,10,-1,10 };
	vector<vector<int>> dp (A.size(),vector<int>(k+1,0));
	dp[0][0] = 0;
	for (int i = 2; i < A.size(); i++)
	{
		for (int j = 0; j <= k; j++)
			if (A[i] >= 0)
			{
				if (A[i - 1] + j >= 0)

					dp[i][j] = dp[i - 2][j + A[i - 1]] + A[i];
				else
				{
					dp[i][j] = A[i];
				}
				if (dp[i][j] > max)
					max = dp[i][j];
			}
	}
	return 0;
}