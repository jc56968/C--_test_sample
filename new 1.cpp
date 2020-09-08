#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int time = 0;
int min(vector<int> A)
{
	int min_ = A[0];
	int ind = 0;
	for (int i = 1; i <= 3; i++)
		if (A[i] < min_)
		{
			min_ = A[i];
			ind = i;
		}
	return ind;
}
void cal(vector<int>& A, vector<int>& C,int a, int b, deque<int>& rm, deque<int>& bm)
{
	vector<int>d(4,0);
	if (rm.empty() && bm.empty())
		return;
	int i = a;
	int j = b;
	int rb = rm.back();
	int rs = rm.front();
	int bb = bm.back();
	int bs = bm.front();
	for (i = a; i <= b; i++)
	{
		if (A[i] == rb && C[i] == 1)
			rb = b - i, d[0] = rb;
		if (A[i] == rs && C[i] == 1)
			rs = i-a, d[0] = rs;
		if (A[i] == bb && C[i] == 0)
			bb = b-i, d[0] = bb;
		if (A[i] == bs && C[i] == 0)
			bs = i-a, d[0] = bs;
	}
	int m1=min(d);
	d.erase(d.begin() + m1);
	if (m1 == 0)
	{
		rb
	}
	if (m1 == 1)
	{
		rs
	}

	if (m1 == 2)
	{
		bb
	}

	if (m1 == 3)
	{
		bs
	}
    int m1= min(d);
	d.clear();
	
	
	return cal(A, C, a + 1, b - 1, rm, bm);



}

int main()
{
	int n;
	cin >> n;
	deque<int> rm(n, 1);
	deque<int> bm(n, 1);
	for (int i = 0; i < n; i++)
		rm[i] = i+1;
	for (int i = 0; i < n; i++)
		bm[i] = i + 1;
	vector<int> A(2 * n, 0);
	vector<int> C(2 * n, 0);
	string s;
	cin >> s;
	for (int i = 0; i < 2 * n; i++)
	{

		if ('R' == s[i])
			C[i] = 1;
		else
			C[i] = 0;
	}
	for (int i = 0; i < 2 * n; i++)
	{
		int t;
		cin >> t;
		A[i] = t;
	}
	cal(A,C, 0, A.size() - 1,rm,bm);
	cout << time;

}