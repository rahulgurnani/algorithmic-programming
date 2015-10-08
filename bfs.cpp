#include <bits/stdc++.h>
using namespace std;
#define MAX_VERTICES 100005
/*
	the function takes as input the graph and the vertex to begin with the start vertex
	does the bfs and prints the vertices in the bfs order.
*/
void bfs(vector<int> graph[], int start)
{
	bool visited[MAX_VERTICES] = {false};
	queue<int> q;
	int current = start;
	q.push(start);
	visited[start] = true;
	while(!q.empty())
	{
		current = q.front();
		q.pop();
		
		cout << current << endl;
		for(int i=0; i<graph[current].size(); i++)
		{
			if(!visited[graph[current][i]])
			{
				q.push(graph[current][i]);
				visited[graph[current][i]] = true;
			}
		}
	}
}
int main()
{
	int n, m;
	int x,y;
	cout << "n, m=";
	cin >> n;
	cin >> m;
	vector<int> graph[n+1];
	for(int i =0 ;i<m ;i++)
	{
		cin >> x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(graph, 0);
	return 0;
}