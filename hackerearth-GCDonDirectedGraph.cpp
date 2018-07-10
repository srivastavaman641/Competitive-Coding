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
vector<int>v[100005],v1[100005];
stack<int>s;
int vis[100005],a[100005];
int c=0;
int ans=INT_MAX;
void dfs(int x)
{
	vis[x]=1;
	c=__gcd(c,a[x]);
	ans=min(ans,c);
	//cout<<x<<endl;
	for(int i=0;i<v[x].size();i++)
	{

		if(!vis[v[x][i]])
			dfs(v[x][i]);
	}
	s.push(x);
}
void dfss(int x)
{
	c=__gcd(c,a[x]);
	ans=min(ans,c);
	//cout<<c<<endl;
	vis[x]=1;
	for(int i=0;i<v1[x].size();i++)
	{
		if(!vis[v1[x][i]]){
			cout<<v1[x][i]<<endl;
			dfss(v1[x][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=min(ans,a[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v1[y].pb(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]){
   			//cout<<i<<endl;
			c=0;
			dfs(i);
			ans=min(ans,c);
		}
	}
	memset(vis,0,sizeof vis);
	while(!s.empty())
	{
		int x=s.top();
		s.pop();
		if(!vis[x])
		{
			c=0;
			dfss(x);
			ans=min(ans,c);
		}
	}
	cout<<ans<<endl;


	return 0;
}
