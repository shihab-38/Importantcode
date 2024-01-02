#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
//ll vis[10000];
ll dis[100005];
ll par[100005];
vector<pair<ll,ll>> v[100005];
void dijkstra (ll src, ll n)
{
	for(int i=1; i<=n ;i++)
	{
		dis[i]=1e18;
	}
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;

	dis[src]=0;
	pq.push({dis[src], src});
	while(!pq.empty())
   {
   	ll d=pq.top().first;

   	ll node=pq.top().second;
   	pq.pop();
   	if(dis[node]<d)
   		continue;
   	for(auto x: v[node])
   	{
         ll adj=x.first;
         ll w=x.second;
         if(d+w< dis[adj])
         {
         	dis[adj]=d+w;
         	par[adj]=node;
         	pq.push({dis[adj],adj});
         }
   	}
   }
}
int main()
{
   int n,e,w;
  // cout<< "Enter the value of node and edges: "<<endl;
   cin>>n>>e;
   for(int i=0; i<e; i++)
   {
   	  int a,b;
   	  cin>>a>>b>>w;
   	  v[a].pb({b,w});
   	  //v[b].pb({a,w});
   }
   dijkstra(1,n);
   // cout<<dis[n]<<endl;
   // for(int i=1; i<=n; i++)
   // {
   // 	cout<<i<< " "<<par[i]<<endl;
   // }
   if(dis[n]==1e18)
   {
   	cout<<-1<<endl;
   	return 0;
   }
   ll x=n;
   vector<ll> pp;
   pp.push_back(n);
   while(x!=1)
   {
       x=par[x];
       pp.push_back(x);
   }
   for(int i=pp.size()-1; i>=0; i--)
   {
   	cout<<pp[i]<< " ";
   }cout<<endl;

  
}