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
	
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
   for(int i=0; i<=n ;i++)
   {
      dis[i]=1e18;
   }
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
   while(1)
   {


   int n,e,w,q,s;
  // cout<< "Enter the value of node and edges: "<<endl;
   cin>>n>>e>>q>>s;
   for(int i=0; i<=n; i++)
   {
      v[i].clear();
   }
   if(n==0 && e==0 && q==0 &&s==0)
      return 0;
   for(int i=0; i<e; i++)
   {
   	  int a,b;
   	  cin>>a>>b>>w;
   	  v[a].pb({b,w});
   }

   dijkstra(s,n);
  while(q--)
  {
      int dd;
      cin>>dd;
      if(dis[dd]==1e18)
      {
          cout<<"Impossible"<<endl;
          
      }
      else
      cout<<dis[dd]<<endl;
  }
   }
  
   

  
}