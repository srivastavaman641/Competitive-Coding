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
vector<ll>v[100005];
int vis[100005];
ll a[100005];
ll k,s,ans=INT_MAX;
void dfs(ll k,ll sum,ll c)
{
	vis[k]=1;
	if(sum>=s && ans>c)
	{
		ans=c;
	}
	for(ll i=0;i<v[k].size();i++)
	{
		if(!vis[v[k][i]])
			dfs(v[k][i],sum+a[v[k][i]],c+1);
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,q;
   cin>>n>>q;
   for(int i=1;i<=n;i++)	
   		cin>>a[i];

   for(int i=1;i<=n-1;i++)
   {
   		ll x,y;
   		cin>>x>>y;
   		v[x].pb(y);
   		v[y].pb(x);
   }
   while(q--)
   {
   		//ll x,y;
   		memset(vis,0,sizeof vis);
   		cin>>k>>s;
   		ans=INT_MAX;
   		dfs(k,a[k],1);
   		if(ans==INT_MAX)
   			ans=-1;
   		cout<<ans<<endl;

   }


   return 0;
}
