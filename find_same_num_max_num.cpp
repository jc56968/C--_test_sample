#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string c;
	cin >> c;
	priority_queue <int, vector<int>, less<int> > T;
	int n = c.size();
	for (int i = n - 1; i >= 0; i--)
	{
		if (T.empty() )
		T.push(int(c[i]) - 48);
		else
		{
			
			
			if (int(c[i]) - 48 <= T.top() )
			{
				T.push(int(c[i]) - 48);
			}
			else
			{
				while (!T.empty())
				{
					int k;
					for (int j = i; j < n; j++)
						if (T.top() == int(c[j]) - 48)
						{
							k = j;
							break;
						}
					swap(c[i], c[k]);
					T.pop();
					if (!T.empty())
					{
						T.push(int(c[k]) - 48);
						for (int m = i + 1; m < n; m++)
						{
							c[m] = char(T.top()+48);
							T.pop();
						}
					}

					cout << c;
					return 0;
					
				}
				
			}

		}
	
		
		
	}
	return 0;
}