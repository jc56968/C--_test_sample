#include<iostream>
#include<vector>
#include<stack>
using namespace std;
long int getFi(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	long int a = 1, b = 1, count = 0;
	for (int i = 2; i <=n; i++)
	{
		count = a + b;
		a = b;
		b = count;
	}
	return count;
}
int main()
{
	int n=5;
	//cin >> n;
	vector<vector<long int>> res(n, vector<long int>(n, 0));
	stack<int >s;
	for (int i = 0; i <= (n * n - 1); ++i)
	{
		s.push(getFi(i));
	}
	int a = 0;
	int b = 0;
	int up = 0, down = n - 1, right = n - 1, left = 0, i = a, j = b-1;
	while (!s.empty())
	{

		
		
		for (j++; j <= right; j++)
		{
			res[i][j] = s.top();
			s.pop();
		}
		up++;
		--j;
		for (i++; i <= down; i++)
		{
			res[i][j] = s.top();
			s.pop();
		}
		--i;
		right--;
		for (j--; j>=left; j--)
		{
			res[i][j] = s.top();
			s.pop();
		}
		++j;
		down--;
		for (i--; i>=up; i--)
		{
			res[i][j] = s.top();
			s.pop();
		}
		++i;
		left++;

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}



