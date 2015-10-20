#include <bits/stdc++.h>
using namespace std;
// in this function we consider the pivot and return its index
int partition(int A[], int l, int r)
{
	int idx = l-1;
	// randomization : here we swap the last element of the array with any element in the array, in this way we are able to randomize the quicksort
	int rnd = (rand() %(r-l+1)) + l;
	swap(A[rnd], A[r]);
	// take the last element as the pivot 
	int p = r;
	for(int i = l;i <r ;i++)
	{
		if(A[i]<=A[p])
		{
			idx++;
			swap(A[idx], A[i]);
		}
	}
	swap(A[idx+1], A[p]);
	return idx+1;
}
// quick_sort recursively quick sort the array A
void quick_sort(int A[], int l, int r)
{
	if(l<r)
	{
		int p = partition(A, l, r);
		quick_sort(A, l, p-1);
		quick_sort(A, p+1, r);
	}
}

int main()
{
	int A[10] = {2,1,10,0, 3,4,5,6,7,8};
	quick_sort(A, 0, 9);
	for(int i = 0;i<10;i++)
		cout << A[i] << " ";
	return 0;
}