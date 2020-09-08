#include<vector>
#include<iostream>
using namespace std;
int min = 10000;
int check(vector<vector<int>> &A,int m,int n,int e0,int x,int l,int i,int j,int count)
{
	if (i == 0 && j == 0)
	{
		int a = i, b = j, con = count;
		while (check(A, m, n, e0, x, l, ++i, j, ++count)) {}
		i = a; b = j; count = con;
		while (check(A, m, n, e0, x, l, i, ++j, ++count)) {}
		i = a; b = j; count = con;
		while (check(A, m, n, e0, x, l, i--, j, ++count)) {}
		i = a; b = j; count = con;
		while (check(A, m, n, e0, x, l, i, j--, ++count)) {}
	}
	if (i >= 0 && i <= m && j >= 0 && j <= n)
	{
		

		if (e0 < A[i][j]  )
		{
			
			
			if(l<A[i][j])
			return 0;
			else
			{
				int a = i, b = j, con = count;
				while (check(A, m, n, l-A[i][j], x - 1, l, ++i, j, ++count)) {}
				i = a; b = j; count = con;
				while (check(A, m, n, l - A[i][j], x - 1, l, i, ++j, ++count)) {}
				i = a; b = j; count = con;
				while (check(A, m, n, l - A[i][j], x - 1, l, --i, j, ++count)) {}
				i = a; b = j; count = con;
				while (check(A, m, n, l - A[i][j], x - 1, l, i, --j, ++count)) {}
				
				
			}
		}
		else
		{
			if (i == m && j == n)
			{
				if (count < min)
					min = count;

			}
			e0 = e0 - A[i][j];
			return 1;
		}
			
	
	}
	else
		return 0;

}
int main()
{
	int m, n, e0, x, l;
	cin >> m >> n >> e0 >> x >> l;
	vector<vector<int>> A(m, vector<int>(n, 0));
	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			int t;
			cin >> t;
			A[i][j]=t;
		}
	check(A, m, n, e0, x, l,0,0,0);
	return 0;
}

//6 8 15 0 45  10 1 30 10 1 10 1 1 20 1 1 30 1 1 10 1 10 50 1 1 1 1 1 100 20 10 20 20 1 1 1 100 20 10 10 10 1 1 100 1 30 30 30 20 100 1 1 0