#include <bits/stdc++.h>
using namespace std;
struct node
{
	/* data */
	int d;
	node* next;
};
struct linked_list
{
	/* data */
	node* head;
	// constructor constructs an empty list
	linked_list()
	{
		head = NULL;
	}
	// insert_sorted function insert_sorteds x into the list
	void insert_sorted(int x)
	{
		if(head == NULL)
		{
			head = new node;
			head->d = x;
			head->next = NULL;
			return;
		}
		node* current = head;
		node* prev = NULL;
		while(current!=NULL && current->d > x)
		{
			prev = current;
			current = current -> next;
		}
		if(prev!=NULL)
		{
			node* next = prev -> next;
			prev->next = new node;
			prev->next->d = x;
			prev->next->next = next;
		}
		else
		{
			node *n = new node;
			n->d = x;
			n->next = head;
			head = n;
		}
	}
	// delete_node deletes the first node with value k
	void delete_node(int k)
	{
		node* h = head;
		node* prev = NULL;
		while( h!=NULL && h->d!=k)
		{
			prev = h;
			h = h->next;
		}
		if(h==NULL)
			return;
		if(prev==NULL)
		{
			node* temp = head;
			head = head -> next;
			delete temp;
		}
		else
		{
			prev->next= h->next;
			delete h;
		}
	}
	// this function prints the list 
	void print_list()
	{
		node* current = head;
		while(current!=NULL)
		{
			cout << current->d << " ";
			current = current->next;
		}
	}
	// this function reverses the list 
	void reverse_list()
	{
		node* current = head;
		node* prev = NULL;
		while(current!=NULL)
		{
			node* temp1 = current->next;
			node* temp2 = current;
			current->next = prev;
			current = temp1;
			prev = temp2;
		}
		head = prev;
	}
	// connect the last node in the list to the node with value x
	void make_cycle(int x)
	{
		node* prev = NULL;
		node* current = head;
		node* tail;
		node* val;
		while(current!= NULL && current->d!=x)
		{
			current = current->next;
		}
		if(current!=NULL)
			val = current;
		else
			return;
		current = head;
		while(current!=NULL)
		{
			prev = current;
			current = current->next;
		}
		tail = prev;
		tail->next = val;
		return;
	}
	// detect_cycle function returns the pointer to the head node of the cycle
	// the logic followed here is that first of all we traverse the linked list with faster pointer and slower pointer now, if cycle length is C, faster will travel 2*C and slower will travel C; so then we make them move C-k each such that they both meet where k is the offset from the 
	node* detect_cycle()
	{
		node* slow, *fast;
		slow = fast = head;
		bool flag = 0;
		while(slow->next!=NULL && fast->next->next!=NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			return NULL;
		fast = head;
		while(fast!=slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	

};
int main()
{
	int n;
	linked_list l;
	cout << "enter n, no of nodes : " ;
	cin >> n;
	int x;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		l.insert_sorted(x);
	}
	l.print_list();
	cin >> x;
	l.delete_node(x);
	l.print_list();
	l.reverse_list();
	l.print_list();
	cin >> x;
	l.make_cycle(x);
	cout << endl << l.detect_cycle() -> d;
	return 0;
}