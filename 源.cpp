#include<iostream>
using namespace std;
int num ;
void djs(int **A, int n,int *B)
{
	int c = -1,I=0;
	for (int i = 1; i < num; i++)
	{
		if (c == -1)
			c = B[i];
		else if (c < B[i]&& A[I][0] != -1&&B[i]!=-1)
		{
			I = i;
			c = B[i];
		}
	}
	for (int i = 1; i < num; i++)
	{
		if (B[i] < B[I] + A[I][i])
			B[i] = B[I] + A[I][i];
	}
	A[I][0] = -1;

	cout << n << "-->" << I << ":" << c << endl;
		if (I != 0)
			djs(A, n, B);
		else
			return;
	



}
void init(int **A,int n)
{
	int *B;
	B = (int *)malloc(sizeof(int)*num);
	for (int i = 1; i < num; i++)
	{
		B[i] = A[1][i];
	}

	djs(A, n,B);
//	A[][];

}
int main()
{
	int **A,n;
	cin >> num;
	num = num +1;
	A = new int*[num];
	cout << sizeof(*A)<<" "<< sizeof(int)*num*num;
	
	for (int i = 1; i < num; i++)
	{
		A[i] = new int[num];
		for(int j = 1;j < num; j++)
		cin >> A[i][j];
	}
	init(A, 1);
}