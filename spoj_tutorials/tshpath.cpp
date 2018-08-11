#include <bits/stdc++.h>
#include <unordered_map>
#define INF 0x3f3f3f3f
using namespace std;
/*struct Compare{
	bool operator() ( pair<int,int> &pp1, pair<int,int> &pp2)
	{
		return pp1.first>pp2.first;
	}
};*/ 
int dijiktra(int src,int dst,vector< vector<pair<int,int> > >& graph)
{
	set<pair<int,int> > ss;
	vector<bool> visited(graph.size(),false);
	vector<int> par(graph.size());
	vector<int> dist(graph.size(),INF);
	dist[src]=0;
	par[src]=-1;
		//priority_queue<pair<int,int>,vector<pair<int,int> >,Compare > pq;
	pair<int,int> pp;
	pp=make_pair(0,src);
	ss.insert(pp);
	while(!ss.empty())
	{
		pp=*(ss.begin());
		ss.erase(ss.begin());
		int u=pp.second;
		visited[u]=true;
		//int w=pp.first;
		//cout<<"outer loop"<<u<<" "<<endl;
		for(auto it=graph[u].begin();it!=graph[u].end();it++)
		{
			int v=(*it).second;
			int w2=(*it).first;
			if(!visited[v])
				par[v]=u;
			//cout<<v<<" "<<w2<<endl;
			if(par[u]!=v&&dist[u]+w2<dist[v])
				{
					if(dist[v]!=INF)
					{
						ss.erase(ss.find(make_pair(dist[v],v)));
					}
					dist[v]=dist[u]+w2;
					ss.insert(make_pair(dist[v],v));
					//cout<<"after"<<dist[v]<<" "<<v<<endl;
				}
		}
	}
	/*while(!pq.empty())
		{
			pp=pq.top();
			cout<<pp.first<<" "<<pp.second<<endl;
			pq.pop();
		}*/
	return dist[dst];
}
int main()
{
	int t;
	cin>>t;
	unordered_map <string,int> hash;
	while(t--)
	{
		int n,indx=0;
		cin>>n;
		vector< vector<pair<int,int> > > graph(n+1); 
		while(n--)
		{
			string s;
			cin>>s;
			hash[s]=++indx;
			//cout<<hash[s]<<endl;
			int neig;
			cin>>neig;
			for(int i=0;i<neig;i++)
			{
				int nr,cost;
				cin>>nr>>cost;
				graph[indx].push_back(make_pair(cost,nr));
				//auto it=graph[indx].begin();				//cout<<it->first<<" "<<it->second<<endl;
			}
		}
		int path;
		cin>>path;
		while(path--)
		{
			string s1,s2;
			cin>>s1>>s2;
			cout<<dijiktra(hash[s1],hash[s2],graph)<<endl;
		}

			/*for(int i=1;i<graph.size();i++)
				for(auto it=graph[i].begin();it!=graph[i].end();++it)
				{
					cout<<i<<" "<<it->first<<endl;
				}
				*/
	}

}