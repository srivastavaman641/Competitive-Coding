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
vector<int>v1,v[10005];
ll ans=0,mx=0,sm=0,sm1=0,idx=0;
int a[10005],vis[10005];
void dfs(int x)
{
	vis[x]=1;
	if(a[x]>mx)
	{
		mx=a[x];
		idx=x;
	}
	if(a[x]==mx && x<idx)
	{
		idx=x;
	}
	sm+=a[x];
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
			dfs(v[x][i]);
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
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]){
			mx=0;
			sm=0;
			idx=0;
			dfs(i);
			ans+=mx;
			sm1+=(sm-mx);
			v1.pb(idx);
		}
	}
	cout<<ans<<" "<<sm1<<endl;
	sort(v1.begin(),v1.end());
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<" ";
	return 0;
}
