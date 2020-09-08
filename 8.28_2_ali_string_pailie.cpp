#include<vector>
#include<iostream>
#include<stack>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int n;
int sum=0;
int a;
void ge(int ik, string &A)
{
	if (ik == A.size())
	{
		if (A[0] != '0' && stoll(A) % a == 0)
		{
			sum++;
		}
	}
	else
	{
		for (int i = ik; i < A.size(); i++)
		{
			swap(A[i], A[ik]);
			ge(ik + 1, A);
			
			swap(A[i], A[ik]);


		}
	}
}
int main()
{
	string A;
	string T=A;
	

	cin >> A >> a;

	

	ge(0, A);
	cout << sum;
	return 0;


}
	