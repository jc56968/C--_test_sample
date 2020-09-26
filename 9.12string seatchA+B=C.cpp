#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		int K = 0;
		string A, B, C;
		cin >> A >> B >> C >> K;
		int i = 0, j = 0, time = 0, k = 0;
		while (1)
		{

			if (i < A.size() && B[j] != C[k] && A[i] != C[k])
			{
				i++;
			}
			if ( j < B.size() && A[i] != C[k] && B[j] != C[k])
			{
				j++;
			}
			if (i < A.size() && j < B.size() && A[i] == C[k] && B[j] == C[k])
			{
				int a = i, b = j;
				while (a < A.size() && k < C.size() && A[a] == C[k])
				{
					a++;
					k++;
				}

				while ( b < B.size() && k < C.size() && B[b] == C[k])
				{
					b++;
					k++;
				}
				time++;
				if (i < A.size() && j<B.size() && a - i > b - j)
				{
					i = a;
				}
				else
				{
					j = b;
				}
			}
			else if (i < A.size()  && k < C.size() && A[i] == C[k])
			{
				while (i < A.size()   && k < C.size() && A[i] == C[k])
				{
					i++;
					k++;
				}
				time++;
			}
			else if ( j < B.size() && k < C.size() && B[j] == C[k])
			{
				while (  j < B.size() && k < C.size() && B[j] == C[k])
				{
					j++;
					k++;
				}
				time++;
			}
			if (i >= A.size() || j >= B.size())
			{
				if (k >= C.size() - 1)
					break;
			}
			if (k >= C.size() - 1)
				break;
		}
		t--;
		if (k == C.size() - 1 && time <= K)
			cout << 1 << endl;
		else
			cout << 0 << endl;

	}
	return 0;
}