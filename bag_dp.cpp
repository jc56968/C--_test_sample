#include<iostream>
#include<vector>
#include<queue>
int main()
{
	//strr();
	int n, m;
	cin >> n >> m;
	int* size = new int[n + 1];
	int* value = new int[n + 1];
	value[0] = 0;
	size[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> value[i] >> size[i];
	int** dp = new int* [n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = new int[m + 1];
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
		
			if (j >= size[i])
				dp[i][j] = max(dp[i - 1][j - size[i]] + value[i], dp[i - 1][j]);
		   else
					dp[i][j] = dp[i - 1][j];
         }
	cout << dp[n][m];
	return 0;
}