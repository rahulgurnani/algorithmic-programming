/* 
	Author : Rahul Gurnani
implementing binary max - heaps  in c++ 
*/
#include <iostream>
using namespace std;
#define MAX_LEN 100000
struct heap
{
	/* data */
	int size;
	int a[MAX_LEN];
	// swape function is used to swap the values of the values at 2 indices
	void swape(int a1, int a2)
	{
		int temp = a[a1];
		a[a1] = a[a2];
		a[a2] = temp;
	}
	// insert is used to insert a value in the heap O(logn)
	void insert(int k)
	{
		a[size++] = k;
		int cur = size-1;
		while(cur > 0)
		{
			int p = (cur-1)/2;
			if(a[p] >= a[cur])
				return;
			swape(p,cur);
			cur = p;
		}
	}
	// delete max deletes the max from the heap and returns it O(logn)
	int delete_max()
	{
		int maxi = a[0];
		a[0] = a[size-1];
		size--;
		heapify(0);
		return maxi;
	}
	// heapify heapifies at index 
	void heapify(int index)
	{
		int l = 2*index + 1;
		int r = 2*index + 2;
		if(l>=size)
			return;
		if(r>=size || a[r] <= a[l])
		{
			if(a[l]>a[index])
			{
				swape(l,index);
				heapify(l);
			}

		}
		else if(a[r]>a[index])
		{
			swape(index,r);
			heapify(r);
		}
		else
			return;
	}
	// make_heap O(n)
	void make_heap()
	{
		for(int i=(size/2) ; i>=0; i--)
			heapify(i);
	}
	// utility function
	void print_heap()
	{
		for(int i = 0 ;i <size;i++)
			cout << a[i] << endl;
	}
};
int main()
{
	heap h;
	int n;
	cout << "n=";
	cin >> n;
	cout<< "values that you want to insert:";
	for(int i=0;i<n;i++)
		cin >> h.a[i];
	h.size = n;
	h.make_heap();
	h.print_heap();
	cout << "max = "<< h.delete_max()<<endl;
	h.print_heap();
	h.insert(10);
	h.print_heap();
}
