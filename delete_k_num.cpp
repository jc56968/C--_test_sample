#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int max(int a, int b)
{
	return a > b ?  a :  b;
}

class Func
{
public:
	bool operator()(const int& a, const int& b)
	{
		return a > b;
	}
};
void strr()
{
	string A;
	int k;
	cin >> A>>k;
	priority_queue<int, vector<int>, Func> C;
	for (int i = 0; i < A.size(); i++)
	{
		if(i<k)
		C.push(int(A[i]) - 48);
		else
		{
			if (C.top() < int(A[i])-48)
			{
				char f = A[i];
				A[i] = char(C.top() + 48);
				C.pop();
				C.push(int(f) - 48);
			}
			else
			{
				int j;
				j = k;
				while (j<A.size()&&int(A[j]) == 48)
					j++;
				if (j == A.size())
					cout << 0 << endl;
				else
				cout << string(A, j);
				return;
			}
		}
	
	}
	return;
}
int main()
{
	strr();
	return 0;
}