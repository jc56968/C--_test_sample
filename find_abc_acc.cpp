#include<iostream>
#include<vector>
using namespace std;
int main()
{
 int n;
 cin >> n;
 vector<int> A;
 for (int i = 100; i <= 999; i++)
 {
  
  int z = n - i;
  if (z < 100)
  {
  }
  else
  {
   int a = (i - i % 100)/100;
   int b = (i - a * 100 - (i - a * 100) % 10) / 10;
   int c = (i - a * 100) % 10;
   int k = a * 100 + 10 * c +   c;
   if (a != b && b != c)
   {
    if (k == z)
    {
     A.push_back(i);
    }
   }

   
  }
 
 }
 cout << A.size() << endl;
 for (auto i : A)
  cout << i <<" "<< n - i << endl;
 return 0;
   
}