#include <bits/stdc++.h>
using namespace std;
int find_root(int n, int parent[])
{
	while(parent[n]!=n) n = parent[n];
	return n;
}
bool find(int p, int q)
{
	return find_root(p) == find_root(q);
}
int union_nodes(int p, int q)
int main()
{
	return 0;
}