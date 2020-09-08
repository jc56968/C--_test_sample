#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int max(int a, int b)
{
	return a >= b ? a : b;
}

int longestArithSeqLength(vector<int>& A) {
	int **dp=new int *[A.size()];
	for (int i = 0; i < A.size(); i++)
	{
		dp[i] = new int[2000];
		memset(dp[i], 0, sizeof(int)*2000);
	}
	int max = 2;
	for (int i = 1; i < A.size(); i++)
		for (int j = 0; j <i; j++)
		{
			int k = A[i] - A[j];
			if (k)
			{
				if (dp[j][1000 + k] + 1 > dp[i][1000 + k])
					dp[i][1000 + k] = dp[j][1000 + k] + 1;
				else
					dp[i][1000 + k] = 1;
				dp[i][1000 + k];
				if (max < dp[i][1000 + k])
					max = dp[i][1000 + k];
			}
		}
	for (int i = 0; i < A.size(); i++)
	{
		delete [](dp[i]);
		
	}
	delete []dp;
	return max+1;
}
int main()
{
	int T;
	cin >> T;
	vector<int >A;
	int n;
	for (int z = 0; z < T; z++)
	{
		A.clear();
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			A.push_back(t);
		}
		cout <<"          "<< longestArithSeqLength(A) << endl;

	}
}