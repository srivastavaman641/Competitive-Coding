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
ll a[505][505];
int vis[505][505];
ll ar,b,h,n,m;
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
vector<pii>v;
int dfs(int i,int j,int len)
{	
	if(i>n || i<1 || j>m || j<1)
		return 0;

	vis[i][j]=1;

	if(i==n || j==m || i==1 || j==1)
		return len;
	int ans=-1;
	for(int k=0;k<4;k++)
	{
		if(!vis[i+x[k]][j+y[k]] && a[i+x[k]][j+y[k]]<=a[i][j] && a[i][j]-a[i+x[k]][j+y[k]]<=h)
		{
			v.pb(mp(i+x[k],j+y[k]));
			ans=dfs(i+x[k],j+y[k],len+1);
			if(ans>0)
				break;
			v.pop_back();
		}
	}
	vis[i][j]=0;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	cin>>ar>>b>>h;
	v.pb(mp(ar,b));
	ll ans=dfs(ar,b,0);
	if(ans==-1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<ans<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}
