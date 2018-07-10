#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 200005
#define ll long long int
#define mp make_pair
#define piii pair<int,pair<int,int> >
 
int n,m,visit[MAX]={0},cnt=0,id[MAX];
vector<int> adj[MAX];
vector<piii> arr;
void dfs(int x)
{
    visit[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        if(visit[adj[x][i]]==0)
            dfs(adj[x][i]);
    }
}
int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void init()
{
    n=0; cnt=0;
    arr.clear();
    for(int i=0;i<MAX;i++)
    {
        id[i]=i;
        visit[i]=0;
        adj[i].clear();
    }
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        init();
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            arr.push_back(mp(abs(u-v),mp(u,v)));
        }
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        for(int i=1;i<=n;i++)
        {
            if(visit[i]==0)
                {dfs(i); cnt++;}
        }
        int cost=cnt-1;
        for(int i=0;i<arr.size();i++)
        {
            int c=arr[i].first, u=arr[i].second.first, v=arr[i].second.second;
            int p=root(u),q=root(v);
            if(p!=q)
                id[p]=q;
            else
                {cost+=c;}
        }
        cout<<cost<<endl;
    }
}