#include<iostream>
#include<vector>
#include<memory>
using namespace std;
int bag_a = 0, bag_b = 0,min=10000000;
int bag(vector<int> &A,int sum,int index, int bag_a = 0,  int bag_b = 0)
{
	if (index >= A.size() && (   bag_a>sum/2 ||bag_b>sum/2  ) )
	{
		return 0;
	}
	if (bag_a == bag_b)
	{
		
		int min_a = sum - bag_a - bag_b;
		if (min_a < min)
		{
			min = min_a;
		}
	}
	if (index < A.size())
	{
		return bag(A, sum, index + 1, bag_a, bag_b)||bag(A, sum, index + 1, bag_a + A[index], bag_b)||bag(A, sum, index + 1, bag_a, bag_b + A[index]);
		//|| 1,0,0==1   1,1,0==1
	}
	return 0;//moren return 1


}
void dynamic_program(vector<int>& A, int sum)
{
	int t[100000];
	memset(t, 0, sizeof(int) * 100000);
	 t[0] = 1;
	 int value = 0;
	for (int i = 0; i < A.size(); i++)
		for (int j = sum; j >=A[i]; j--)
			
			t[j] = t[j] | t[j - A[i]];//t[j]==1 :存在t[a]+t[b]=sum;
	for (int j = sum; j > 0; j--)
	{
		if (j % 2 == 1)
			continue;

		else
		{
			if (t[j] == 1 && t[j / 2] == 1)
			{
				value = sum - j;
				break;
			}
		}
	}
	cout << value<<endl;

}
class v3
{
public:
	v3() {  }
	int e ;
};
class v44
{
public:
	virtual void ukk() { cout << "uk"; }
	virtual void ukk2() { cout << "uk2"; }
	int mk23;
};
class v45:virtual public v44
{
	
public:
	virtual void uk() {}
	v3 v;
	int a;
	int b;
	virtual void ukk() { cout << "135"; }
	
	int foo(int value)
	{
		return b;
	}
	v45() {}
	v45(int value):a(foo(value)),b(value) {}
};
class base1
{
public:
	virtual ~base1() {}
	virtual void clone() { cout << "base1"; }
	virtual void speak() {}
	void A(int y) { cout << "1"; }
	int a;
};
class base2 
{
public:
	virtual ~base2() {}
	 void A() { cout << "2"; }
	virtual void clone() { cout << "base2"; }
	virtual void mutab() {}
	int a;
};
class derive:public base1,public base2
{
public:
	virtual void clone() { cout << "derive"; }
	virtual ~derive() {}
	void mac() {}
	int a;
};
class derive2 :public virtual base1
{
public:
	virtual void clone4() { cout << "derive"; }
	virtual void clone() { cout << "derive"; }
	virtual ~derive2() {}
};
class io
{
	int i;
	virtual void uk() {}
};
int main()
{
	io ii;
	
	derive C;
	derive2 C2;
	base2 UK;
	UK.base1::clone();
	UK.A();
	C.A(5);
	
	UK.base1::a = 28;
	base2* p=new base2;
	

	void (base2:: * ptr)() = &base2::clone;
	printf("%p\n", &derive::mac);
	(C.*ptr)();
	(p->*ptr)();
	printf("%p\n", ptr);
	printf("%p\n", &base2::clone);
	


	v45 t(5),t2;
	t.ukk2();
	t.v45::v45();
	t.v45::v45(t2);
	
	vector<int> A = { 30,60,5,15,30};
	int sum = 0;
	for (auto a : A)
		sum += a;
	bag(A, sum, 0);
	dynamic_program(A, sum);
	cout << min;
}
