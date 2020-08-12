#include<iostream>
using namespace std;
struct Noda
{
	char data;
	Noda *next=NULL;
	Noda *link=NULL;
};
Noda * creatlist(Noda *q)
{
	char a = ' ';
	q= (Noda *)malloc(sizeof(Noda));
	(*q).next = NULL;
	(*q).link = NULL;
	while (a== ' ' )
	{
		a = getchar();
	}
	(*q).data = a;
	
 if ((*q).data == '\n')
	 return q;
 else
 {
	 (*q).link = creatlist((*q).link);
	 return q;
 }
}
char S[20];
int num = 0;
int check()
{
	for (int j = 1; j < num-1  ; j++)
		if (S[j] == S[num -1])
		{
			cout << "yes";
			return 1;
		}
	return 0;
}
void dft(Noda *q, Noda *p)
{
	Noda *e;
	e = p;

		while ((*e).next != NULL)
		{

			if ((*e).data == (*q).data)
			{
				Noda *f = e;;
				while ((*f).link != NULL && (*(*f).link).data != '\n')
				{
					S[num++] = (*f).data;
					if (check() == 1)
						return;

					if (int((*f).link) != 0xcdcdcdcd && (*(*f).link).data != '\n' && (*f).link != NULL)
						f = (*f).link;
					else
						return;
					dft(f, p);
				}

			}
			e = (*e).next;
		}
	
	
	
    

}
int main()
{
	Noda *p, *q,*cc,*bb;
	p = (Noda *)malloc(sizeof(Noda));
	q = (Noda *)malloc(sizeof(Noda));
	cc = (Noda *)malloc(sizeof(Noda));
	bb = (Noda *)malloc(sizeof(Noda));
	(*bb).next = NULL;
	(*bb).link = NULL;
	
	int a;
	cin >> a;
	(*p).data='0';
	 (*p).next=q;
	
	for (int i = 1; i <= a; i++)
	{
		cin >> (*q).data;
		(*q).link=creatlist((*q).link);
		
		cc = (Noda *)malloc(sizeof(Noda));
		(*q).next = cc;
		q = cc;
		
	}
	(*cc).next = NULL;
	(*cc).link = NULL;
	q = p;
	dft(q->next,q->next);
	while ((*q).next != NULL)
	{
		if (int((*q).link) != 0xdddddddd)
		{
			q = (*q).next;
			bb = q;


			while ((*bb).link != NULL)
			{
				cout << (*bb).data << "->";
				if (int((*bb).link) != 0xcdcdcdcd)
					bb = (*bb).link;
			}

			free(bb);
			cout << endl;
		}
	

	}
	system("pause");
}

