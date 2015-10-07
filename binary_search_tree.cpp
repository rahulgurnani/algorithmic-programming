#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{
	int val;
	node* left;
	node* right;
};
struct tree
{
	node *head;
	int size;
	tree()
	{
		size = 0;
		head = NULL;
	}
	void insert(int key)
	{
		size++;
		if(head==NULL)
		{
			head = (node*)malloc(sizeof(node));
			head->val = key;			
			return;
		}
		node* cur = head;
		node* prev = head;
		while(cur!=NULL)
		{
			prev = cur;
			if(cur->val < key)
				cur = cur->right;
			else 
				cur = cur->left;		
		}		
		
		if(prev->val< key )
		{
			prev->right = (node*)malloc(sizeof(node));
			prev->right->val = key;
		}
		else
		{
			prev->left = (node*)malloc(sizeof(node));
			prev->left->val = key;
		}
	}
	void print_node(node* n)
	{
		if(n==NULL)
			return;
		node* l = n->left;
		node* r = n->right;
		if(l!=NULL)
		{
			print_node(l);
		}
		printf("%d\n",n->val );
		if(r!=NULL)
		{
			print_node(r);
		}
	}
};
int main()
{
	tree T;
	T.insert(1);
	T.insert(10);
	T.insert(5);
	T.insert(100);
	T.insert(101);
	T.insert(50);
	T.print_node(T.head);
	return 0;
}