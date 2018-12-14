#include <bits/stdc++.h>
#define V 4
#define INF INT_MAX
using namespace std;
void print(int path[][V],int i,int j)
{
	if(path[i][j]==i)
	{
		return;
	}
	print(path,i,path[i][j]);
	cout<<path[i][j]<<" ";
}
void printsol(int cost[][V],int path[][V])
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(cost[i][j]==INF)
				cout<<"inf ";
			else
				cout<<cost[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
				cout<<path[i][j]<<" ";		
		}
		cout<<endl;
	}
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(i!=j&&path[i][j]!=-1)
			{
				cout<<"shortest path "<<i <<"to"<<j<<"("<<i<<" ";print(path,i,j);
				cout<<j<<") "<<cost[i][j]<<endl;
			}
		}
	}
}
void allpairshp(int g[][V])
{
	int cost[V][V],path[V][V];
	for(int u=0;u<V;u++)
	{
		for(int v=0;v<V;v++)
		{
			cost[u][v]=g[u][v];
			if(u==v)
			{
				path[u][v]=0;
			}
			else if(cost[u][v]!= INF)
			{
				path[u][v]=u;
			}
			else
				path[u][v]=-1;
		}
	}
	int i;
	for(int k=0;k<V;k++)
	{
		for( i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(cost[i][k]!=INT_MAX&&cost[k][j]!=INT_MAX&&cost[i][k]+cost[k][j]<cost[i][j])
				{
					cost[i][j]=cost[i][k]+cost[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
		
	}

	printsol(cost,path);
}
int main()
{
	  int graph[V][V] = { {0,   5,  INF, 10}, 
                        {INF, 0,   3, INF}, 
                        {INF, INF, 0,   1}, 
                        {INF, INF, INF, 0} 
                      }; 
	allpairshp(graph);
}