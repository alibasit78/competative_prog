#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int> > &g,int src,vector<int> &visited)
{
	visited[src]=1;
	cout<<src<<" ";
	for(auto it=g[src].begin();it!=g[src].end();++it)
	{
		if(visited[*it]!=1)
		{
			dfs(g,*it,visited);
		}
	}
}
int bfs(vector<vector<int> > &g,int src,vector<int> &visited)
{
	list<int> queue;
	queue.push_back(src);
	visited[src]=1;
	while(!queue.empty())
	{
		int x=queue.front();
		cout<<x<<" ";
		queue.pop_front();
		for(auto it=g[x].begin();it!=g[x].end();it++)
		{
			if(visited[*it]!=1)
			{
				visited[*it]=1;
				queue.push_back(*it);
			}
		}

	}
}
int traverse(vector<vector<int> > &g,int src,int choice)
{
	vector<int> visited(g.size(),0);
	if(choice==0){
		dfs(g,src,visited);
		cout<<endl;
	}
	else{
		bfs(g,src,visited);
		cout<<endl;
	}
}
int main()
{
	int t,c=0;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int temp=n;
		vector<vector<int> > g(n+1);
		while(temp--)
		{
			int i,m;
			cin>>i>>m;
			while(m--)
			{
				int vert;
				cin>>vert;
				g[i].push_back(vert);
			}
		}
		cout<<"graph "<<++c<<endl;
		while(1)
		{
			int src,choice;
			cin>>src>>choice;
			if(src==0&&choice==0)
				break;
			traverse(g,src,choice);
		}
	}


}