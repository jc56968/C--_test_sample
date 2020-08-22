#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int CC(int a, int b)
{
 int m=1, n=1,q=1;
 for (int i = 1; i <= a; i++)
  m = m * i;
 for (int i = 1; i <= b; i++)
  n = n * i;
 for (int i = 1; i <= a-b; i++)
  q = q * i;
 return m/q/ n;
}
int main() {
 
 int n;
 cin >> n;
 vector<int>p(n, 0);
 vector<int> t (200,0);
 for (int j = 0; j < n; j++)
 {
  cin >> p[j];
  t[p[j]]++;
 }
 int m = t[0];
 sort(p.begin(), p.end());
 int sum = 1;
 for (int j = 1; j <=p[n-1]; j++)
 {
  m = t[j-1];
  int k = 2 * m;
  
  int y = k-t[j] ;
  sum =  CC(k,y)* sum;
 }
 cout << sum;
 return 0;

}