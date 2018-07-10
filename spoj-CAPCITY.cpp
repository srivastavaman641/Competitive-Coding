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
vector<int>v[100005],v1[100005],ans[100005];
stack<int>s;
int vis[100005],in[100005];
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v1[x].size();i++)
	{
		if(!vis[v1[x][i]])
			dfs(v1[x][i]);
	}
	s.push(x);
}
int dfss(int x,int cnt)
{
	vis[x]=cnt;
	int c=1;
	ans[cnt].pb(x);
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
			c+=dfss(v[x][i],cnt);
	}
	return c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v1[y].pb(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
	}
	memset(vis,0,sizeof vis);
	int cnt=0;
	while(!s.empty())
	{
		int x=s.top();
		s.pop();
		if(!vis[x])
		{
			cnt++;
			dfss(x,cnt);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v1[i].size();j++)
		{
			if(vis[i]!=vis[v1[i][j]])
				in[vis[v1[i][j]]]++;
		}
	}
	int an=0,c=0;
	for(int i=1;i<=cnt;i++)
	{
		if(in[i]==0){
			c++;
			an=i;
		}
	}
	if(c>1)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<ans[an].size()<<endl;
	sort(ans[an].begin(),ans[an].end());
	for(int i=0;i<ans[an].size();i++)
		cout<<ans[an][i]<<" ";

	return 0;
}
