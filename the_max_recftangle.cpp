#include<vector>
#include<iostream>
#include<stack>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int B[] = { 1, 1, 1, 1 ,2 ,1 ,1 };
	int A[] = { 5,2,5,4,5,1,6 };
	int n = 7;
	stack<int> t;
	int left[7] = { -1,-1,-1,-1,-1,-1,-1 };
	int right[7] = {7,7,7,7,7,7,7 };
	for (int i = 0; i < n; i++)
	{
		while (!t.empty() && A[t.top()] > A[i])
		{
			right[t.top()] = i;
			t.pop();
		}
		t.push(i);
	
	}
	while (!t.empty())
	{
		t.pop();
	}
	for (int i = n-1; i >= 0; i--)
	{
		while (!t.empty() && A[t.top()] > A[i])
		{
			left[t.top()] = i;
			t.pop();



		}
		t.push(i);

	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = left[i] + 1;
		int j = right[i];
		int L = 0;
		for (; x < j; x++)
		{
			L = L + B[x];
		}
		ans=max(ans,L*A[i]);
	}

	return 0;
}

