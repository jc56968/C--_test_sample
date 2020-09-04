#include<iostream>
using namespace std;
int max(int a,int b)
{
	return a > b ? a : b;
}
int main() {
	
		int m, d, n;
	
		cin >> m >> d >> n;
	
		int* mem = new int[n + 1];
	
		int* disk = new int[n + 1];
	
		int* value = new int[n + 1];
	
		for (int i = 1; i <= n; i++)
			
			cin >> mem[i] >> disk[i] >> value[i];
	
		mem[0] = 0;
	
		disk[0] = 0;
	

		
		int*** dp = new int** [n + 1];
	
		for (int i = 0; i <= n; i++)
			
		{
			
				dp[i] = new int* [m + 1];
			
				for (int j = 0; j <= m; j++)
					
					dp[i][j] = new int[d + 1];
			
		}
	
		for (int i = 0; i <= d; i++)
			
		{
			
				dp[0][0][i] = 0;
			
		}
	
		for (int i = 0; i <= m; i++)
			
			dp[0][i][0] = 0;
	
		for (int i = 0; i <= n; i++)
			
			dp[i][0][0] = 0;
	
		for (int k = 1; k <= n; k++)
			
			for (int i = 1; i <= m; i++)
				
				for (int j = 1; j <= d; j++)
					
				{
					
						if (mem[k] <= i && disk[k] <= j)
							
							dp[k][i][j] = max(dp[k - 1][i - mem[k]][j - disk[k]] + value[k], dp[k - 1][i][j]);
					
						else
							
							dp[k][i][j] = dp[k - 1][i][j];
					
				}
	

		cout << dp[n][m][d] << endl;
}
