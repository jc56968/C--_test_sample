#include<vector>
#include<iostream>
#include<memory>
#include<stack>
#include<malloc.h>
using namespace std;
vector<int>::iterator search(vector<int>::iterator begin, vector<int>::iterator end, int a)
{
	auto b = begin;
	auto e = end;
	auto mid = b + (e - b) / 2;
	while (mid != e)
	{
		if (*mid >= a)
		{
			e = mid;
			mid = b + (e - b) / 2;


		}
		else
		{
			b = mid + 1;
			mid = b + (e - b) / 2;

		}
	}
	return mid;

}
int* out()
{
	int* p, * q;
	if (1)
	{
		int C = 20;
		q = &C;
		int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
		p = A;
	}
	return q;
}
struct Tree
{
	int value;
	Tree* left = NULL;
	Tree* right = NULL;

};
deque<Tree*> T;
stack<Tree*> PP;
deque<Tree*> T2;
void floor_visit()
{
	while (!T.empty())
	{
		while (!T.empty())
		{

			Tree* root = T.front();
			PP.push(T.front());
			T.pop_front();
			if (root->left != NULL)

				T2.push_back(root->left);



			if (root->right != NULL)

				T2.push_back(root->right);

		}
		PP.push(NULL);
		T.swap(T2);
	}

}
void floor_date()
{
	Tree* root = new Tree;
	root->value = 24;

	Tree* node1 = new Tree;
	node1->value = 8;

	Tree* node2 = new Tree;
	node2->value = 27;
	root->left = node1;
	root->right = node2;
	T.push_front(root);

	Tree* node3 = new Tree;
	node3->value = 97;
	node2->right = node3;
	floor_visit();
	while (!PP.empty())

	{
		if (PP.top() != NULL)

			cout << PP.top()->value << " ";

		else
			cout << endl;
		PP.pop();
	}
}



int main()
{
	
	floor_date();

	vector<int > c = { 1, 2,3,4,5,6,8,9,9,9,9,11 };
	
	auto i = search(c.begin(), c.end(), 9);
	cout << endl;
	
	return 0;
}