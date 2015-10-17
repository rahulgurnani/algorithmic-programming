#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
//defines-general
// this dijkstra algorithm function takes as input the graph and outputs the distance vector
struct compare
{
	/* data */
	bool operator()(const pair<int, long long> &a, const pair<int, long long> &b)
	{
		if(a.second < b.second)
			return true;
		return false;
	}
};
// the function returns array of distances.
long long* dijkstra(vector<pair<int, int> > graph[], int n, int u)
{
	static long long distances[20005];
	for(int i = 0 ; i<20005; i++)
		distances[i] = -1;
	set<pair<int, long long>, compare > Q;
	distances[u] = 0;
	Q.insert(make_pair(u, (long long ) 0));
	while(!Q.empty())
	{
		pair<int, long long> top = *Q.begin();
		int v = top.first;
		long long d = top.second;
		Q.erase(Q.begin());
		for(int i = 0;i < graph[v].size(); i++)
		{
			int v2 = graph[v][i].first;
			long long cost = graph[v][i].second;
			if(distances[v2] > distances[v] + cost || distances[v2] == -1)
			{
				if(distances[v2]!= -1)
				{
					Q.erase(make_pair(v2, distances[v2]));
				}
				distances[v2] = distances[v] + cost;
				Q.insert(make_pair(v2, distances[v2]) );
			}
		}
	}
	return distances;
}
