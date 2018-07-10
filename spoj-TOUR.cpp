#include<bits/stdc++.h>
#define ll long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
#define pii pair<int,int>

using namespace std;
vector<int>v[1005],v1[1005];
int vis[1005],in[1005];
stack<int>s;
map<int,int>m;
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
			dfs(v[x][i]);
	}
	s.push(x);
}
int dfss(int x,int c)
{
	int cnt=1;
	vis[x]=c;
	for(int i=0;i<v1[x].size();i++)
	{
		if(!vis[v1[x][i]])
			cnt+=dfss(v1[x][i],c);
	}
	return cnt;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		int n;
   		cin>>n;
   		for(int i=0;i<=n;i++)
   		{
   			vis[i]=0;
   			v1[i].clear();
   			v[i].clear();
   			in[i]=0;
   		}
   		m.clear();
   		for(int i=1;i<=n;i++)
   		{
   			int x;
   			cin>>x;
   			for(int j=0;j<x;j++)
   			{
   				int y;
   				cin>>y;
   				v1[i].pb(y);
   				v[y].pb(i);
   			}
   		}
   		for(int i=1;i<=n;i++)
   		{
   			if(!vis[i])
   				dfs(i);
   		}
   		memset(vis,0,sizeof vis);
   		int cnt=1;
   		while(!s.empty())
   		{
   			int x=s.top();
   			s.pop();
   			if(!vis[x])
   			{
   				m[cnt]=dfss(x,cnt);
   				cnt++;
   			}
   		}
   		for(int i=1;i<=n;i++)
   		{
   			for(int j=0;j<v[i].size();j++)
   			{
   				if(vis[i]!=vis[v[i][j]])
   				{
   					in[vis[v[i][j]]]++;
   				}
   			}
   		}
   		int c=0,ans=0;
   		for(int i=1;i<=cnt-1;i++)
   		{
   			if(in[i]==0)
   			{
   				c++;
   				ans=m[i];
   			}
   		}
   		if(c>1)
   		{
   			cout<<0<<endl;
   			continue;
   		}
   		else
   		{
   			cout<<ans<<endl;
   		}

   }
   return 0;
}
