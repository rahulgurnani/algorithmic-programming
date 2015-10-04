// AUTHOR : RAHUL GURNANI
// this file contains all types of variants of binary search 
#include <iostream>
using namespace std;
// the following function returns maximum index such that a[index]<=x
int binary_search_lower(int* a, int x, int low, int hi)
{
	if(x<a[low])
		return -1;
	if(x>a[hi])
		return hi;
	int mid;
	while(hi>=low)
	{
		mid = (hi+low)/2;
		if(a[mid] > x)
		{
			hi = mid - 1;
		}
		else 
		{
			low = mid + 1;
		}
	}
	return low-1;
}
// the following function returns smallest index such that a[index]>=x
int binary_search_higher(int *a, int x, int low, int hi)
{
	if(x>a[hi])
		return -1;
	if(x<a[low])
		return low;
	int mid;
	while(hi>=low)
	{
		mid = (hi + low)/2;
		if(a[mid] < x )
		{
			low = mid + 1;
		}
		else
		{
			hi = mid -1;
		}
	}
	return hi+1;
}
// the following function returns -1 if element is not present in the array else returns index such that a[index] = x
int binary_search(int* a, int x, int low, int hi)
{
	int mid;
	while(hi>=low)
	{
		mid = (hi+low)/2;
		if(a[mid] > x)
		{
			hi = mid - 1;
		}
		else if(a[mid] == x)
		{
			return mid;
		}
		else
		{
			// a[mid] < x
			low = mid+1;
		}
	}
	return -1;
}
int main()
{
	int n;
	cout << "n=";
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int q;
	for(int i=0;i<10;i++)
	{
		cin >> q;
		cout << "lower" <<binary_search_lower(a,q,0,n-1) << endl;
		cout <<"higher" << binary_search_higher(a,q,0,n-1) << endl;
		cout <<"normal=" <<binary_search(a,q,0,n-1) << endl;
	}
	return 0;
}