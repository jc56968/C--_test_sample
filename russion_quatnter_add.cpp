#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int max(vector<int>& A)
{
	int max = -1;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}
int min(vector<int>& A)
{
	int min = 100;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] <= min)
			min = A[i];
	}
	return min;
}
int main()
{
	string c;
	cin >> c;
	vector<int> p(c.size(), 0);
	for (int i = 0; i < c.size(); i++)
		p[i] = int(c[i]) - 48;
	string c1;
	cin >> c1;
	vector<int>q(c1.size(), 0);
	for (int i = 0; i < c1.size(); i++)
		q[i] = int(c1[i]) - 48;
	int dp = 1000;
	for (int i = 0; i <= c.size() - c1.size(); i++)
	{
		vector<int> p1 = p;
		vector<int> q1 = q;
		for (int j = 0; j < c1.size(); j++)
		{
			p1[i + j] = p1[i + j] + q1[j];
		}
			int s = max(p1) - min(p1);
			if (s < dp)
				dp = s;
			cout << dp << endl;
		
	}
}