
#include<iostream>
#include<vector>

#include<set>
#include<algorithm>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
struct point 
{
	int a;
	int b;
	point(int a = 0, int b = 0) :a(a), b(b) {}
};
struct cmp
{
	bool operator()(point a, point b)
	{
		return a.b >b.b;
	}
};
int main()
{
	int k, K, n;
	cin >> K;
	while (K != 0)
	{
		cin >> n >> k;
		vector<point> A;
		vector< vector<int>> chi(n+1, vector<int>(n+1, 0));
		for (int i = 1; i <= n; i++)
		{
			int j;
			cin >> j;
			A.push_back(point(i, j));
		}
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			chi[a][b] = 1;
			chi[b][a] = 1;
		}
		int M = 0;
		vector< vector<int>> dp(n+1, vector<int>(k + 1, 0));
		sort(A.begin(), A.end(), cmp());
		
		for (int i = 0; i < n; i++)
		{
			int sum = A[i].b;
			int hk = k-1;
			int j=0;
			while (hk != 0&&j<n)
			{
				for ( j = i + 1; j < n; j++)
				{
					if (chi[A[i].a ][A[j].a ] != 1&&hk>0)
					{
						sum += A[j].b;
						hk--;
					}
				}
			}
			if (sum > M)
				M = sum;

		}

			




		cout << M << endl;
		K--;
	}
}

/*
1
5 2
2 3 1 5 4
1 2
1 3
1 4
1 5
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int m, n;
struct point
{
	int a;
	int b;
	point(int a = 0, int b = 0) :a(a), b(b) {}
};
struct cmp
{
	bool operator()(const point &a, const point &b) const
	{
		if (a.a < b.a)
			return 1;
		else if (a.a == b.a)
		{
			if (a.b < b.b)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
};
void bfs(vector<vector<char>>& A, int a, int b)
{
	int sum = 0;
	set<point,cmp> chong;
	set<point,cmp> v;
	queue<point> T;
	T.push(point( a, b ));
	while (!T.empty())
	{
		queue<point> T2;
		while (!T.empty())
		{
			point x = T.front();
			int a = x.a, b = x.b;
			T.pop();
			if(a>=0&&a<m&&b>=0&&b<n)
			{
				if (A[a][b] != '1')
				{
					if (A[a][b] == 'X')
						v.insert(x);
					else if (chong.find(x) == chong.end())
					{
						chong.insert(x);
						T2.push(point{ a + 1, b });
						T2.push(point{ a , b + 1 });
						T2.push(point{ a - 1, b });
						T2.push(point{ a , b - 1 });
					}
				}
			}
			
		}
		if (v.empty())
		{
			swap(T, T2);
			sum++;
		}
		else
		{
			cout << sum << endl;
			for (auto i = v.begin(); i != v.end(); i++)
			{
				cout << (*i).a << " " << (*i).b <<" ";
			}
			return;
		}
	}

	cout << 0 << endl;
	

}
*/
/*
int main()
{
	int  a, b;
	cin >> m >> n;
	vector<vector<char>>A(m, vector<char>(n, 0));
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			A[i][j] = s[j];
			if (s[j] == 'T')
			{
				a = i;
				b = j;
			}
		}
	}
	bfs(A, a, b);


}
*/
/*#include<vector>
#include<iostream>
using namespace std;
int check(vector<vector<int>> &B)
{
	vector<vector<int>>  A0 = {
{0,0, 0, 0, 0, 0 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0},
{0 ,0 ,1 ,1 ,0, 0, 1 ,1, 0, 0},
{0 ,0 ,1 ,1 ,0 ,0 ,1, 1 ,0 ,0},
{0 ,0 ,1, 1 ,0 ,0 ,1 ,1, 0, 0},
{0 ,0 ,1 ,1 ,0, 0 ,1, 1, 0, 0},
{0 ,0 ,1, 1 ,0, 0 ,1 ,1, 0, 0},
{0 ,0, 0 ,1 ,1 ,1 ,1 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0}
	};

	vector<vector<int>>  A1 = {
{0,0, 0, 0, 0, 0 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,1 ,1, 1, 0 ,0, 0, 0},
{0 ,0 ,0 ,0 ,1 ,1 ,0, 0 ,0 ,0},
{0 ,0 ,0, 0 ,1 ,1 ,0 ,0, 0, 0},
{0 ,0 ,0 ,0 ,1, 1 ,0, 0, 0, 0},
{0 ,0 ,0, 0 ,1, 1 ,0 ,0, 0, 0},
{0 ,0, 0 ,1 ,1 ,1 ,1 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0}
	};

	vector<vector<int>>  A2= {
{0,0, 0, 0, 0, 0 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0},
{0 ,0 ,1 ,1 ,1, 1, 1 ,1, 0, 0},
{0 ,0 ,0 ,0 ,0 ,1 ,1, 0 ,0 ,0},
{0 ,0 ,0, 0 ,1 ,1 ,0 ,0, 0, 0},
{0 ,0 ,0 ,0 ,1, 1 ,0, 0, 0, 0},
{0 ,0 ,0, 1 ,1, 0 ,0 ,0, 0, 0},
{0 ,0, 1 ,1 ,1 ,1 ,1 ,1 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0}
	};

	vector<vector<int>>  A3 = {
{0,0, 0, 0, 0, 0 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0},
{0 ,0 ,1 ,1 ,0, 0, 1 ,1, 0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,1, 1 ,0 ,0},
{0 ,0 ,0, 1 ,1 ,1 ,1 ,0, 0, 0},
{0 ,0 ,0 ,0 ,0, 0 ,1, 1, 0, 0},
{0 ,0 ,1, 1 ,0, 0 ,1 ,1, 0, 0},
{0 ,0, 0 ,1 ,1 ,1 ,1 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0}
	};
	vector<vector<int>>  A4 = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 },
		{ 0 ,0 ,0 ,1 ,1, 1, 0, 0, 0, 0 },
		{ 0 ,0 ,1 ,1 ,1 ,1 ,0, 0 ,0 ,0 },
		{ 0 ,1 ,1, 0 ,1 ,1, 0 ,0, 0, 0 },
		{ 0 ,1 ,1 ,1 ,1, 1 ,1, 1, 0, 0 },
		{ 0 ,0 ,0, 0 ,1, 1 ,0 ,0, 0, 0 },
		{ 0 ,0, 0 ,0 ,1 ,1 ,0 ,0 ,0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0 }
	};
	vector<vector<int>>  A5= {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 },
		{ 0 ,0 ,1 ,1 ,1, 1, 1 ,1, 0, 0 },
		{ 0 ,0 ,1 ,1 ,0 ,0 ,0, 0 ,0 ,0 },
		{ 0 ,0 ,1, 1 ,1 ,1 ,1 ,0, 0, 0 },
		{ 0 ,0 ,0 ,0 ,0, 0 ,1, 1, 0, 0 },
		{ 0 ,0 ,1, 1 ,0, 0 ,1 ,1, 0, 0 },
		{ 0 ,0, 0 ,1 ,1 ,1 ,1 ,0 ,0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0 }
	};

	vector<vector<int>>  A6 = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 },
		{ 0 ,0 ,1 ,1 ,0, 0, 0 ,0, 0, 0 },
		{ 0 ,0 ,1 ,1 ,0 ,0 ,0, 0 ,0 ,0 },
		{ 0 ,0 ,1, 1 ,1 ,1 ,1 ,0, 0, 0 },
		{ 0 ,0 ,1 ,1 ,0, 0 ,1, 1, 0, 0 },
		{ 0 ,0 ,1, 1 ,0, 0 ,1 ,1, 0, 0 },
		{ 0 ,0, 0 ,1 ,1 ,1 ,1 ,0 ,0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0 }
	};
	vector<vector<int>>  A7 = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
		{ 0 ,0 ,1 ,1 ,1, 1, 1 ,1, 0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,1, 1 ,0 ,0 },
		{ 0 ,0 ,0, 0 ,0 ,1 ,1 ,0, 0, 0 },
		{ 0 ,0 ,0 ,0 ,1, 1 ,0, 0, 0, 0 },
		{ 0 ,0 ,0, 1 ,1, 0 ,0 ,0, 0, 0 },
		{ 0 ,0, 1 ,1 ,0 ,0 ,0 ,0 ,0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0 },
		{ 0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0 }
	};

	vector<vector<int>>  A8 = {
{0,0, 0, 0, 0, 0 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0},
{0 ,0 ,1 ,1 ,0, 0, 1 ,1, 0, 0},
{0 ,0 ,1 ,1 ,0 ,0 ,1, 1 ,0 ,0},
{0 ,0 ,0, 1 ,1 ,1 ,1 ,0, 0, 0},
{0 ,0 ,1 ,1 ,0, 0 ,1, 1, 0, 0},
{0 ,0 ,1, 1 ,0, 0 ,1 ,1, 0, 0},
{0 ,0, 0 ,1 ,1 ,1 ,1 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0}
	};
	vector<vector<int>> A9 = {
		{0 ,0, 0, 0, 0, 0 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0},
{0 ,0 ,1 ,1 ,0, 0, 1 ,1, 0, 0},
{0 ,0 ,1 ,1 ,0 ,0 ,1, 1 ,0 ,0},
{0 ,0 ,0, 1 ,1 ,1 ,1 ,1, 0, 0},
{0 ,0 ,0 ,0 ,0, 0 ,1, 1, 0, 0},
{0 ,0 ,0, 0 ,0, 0 ,1 ,1, 0, 0},
{0 ,0, 0 ,1 ,1 ,1 ,1 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0},
{0 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0 ,0}
	};
	vector<vector<vector<int >>> S;
	S.push_back(A0);
	S.push_back(A1);
	S.push_back(A2);
	S.push_back(A3);
	S.push_back(A4);
	S.push_back(A5);
	S.push_back(A6);
	S.push_back(A7);
	S.push_back(A8);
	S.push_back(A9);
	for (int k = 0; k <10; k++)
	{
		for (int i = 0; i < 10; i++)
		{
			int j = 0;
			for ( j = 0; j < 10; j++)
			{
				if (B[i][j] != S[k][i][j])
				{
					break;
				}
				if (i == 9 && j == 9 )
				{
					return k;
				}
			}
			if (j!=10&&B[i][j] != S[k][i][j])
			{
				break;
			}
		}
	}

		

	return -1;
}
int main()
{
	int T;
	cin >> T;
	while (T != 0)
	{
		int n;
		cin >> n;
		vector<vector<int>> A(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				int s;
				cin >> s;
				A[i][j] = s;
			}
		int k = n / 10;
		if(k==1)
			cout << check(A);
		else
		{
			vector<vector<int>> B(10, vector<int>(10, 0));
			for (int i = 0; i < n; i = i + k)
				for (int j = 0; j < n; j = j + k)
				{
					int sum = 0;
					for (int p = i; p < i + k; p++)
						for (int q = j; q < j + k; q++)
						{
							sum += A[p][q];
						}
					if (sum >= k * k / 2)
						B[i / k][j / k] = 1;
				}
			cout << check(B);
		}


		T--;
	}
}
*/
/*
2
10
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 1 1 0 0 1 1 0 0
0 0 1 1 0 0 1 1 0 0
0 0 0 1 1 1 1 1 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/