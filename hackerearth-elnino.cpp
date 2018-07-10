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
//int vis[200005];
ll a[300005],A[300005];
vector<ll>v[300005];
void dfs(ll x,ll dis)
{
	//vis[x]=1;
	A[dis]++;
	for(ll i=0;i<v[x].size();i++)
	{
			dfs(v[x][i],dis+1);
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,m;
   cin>>n>>m;
  // memset(vis,0,sizeof vis);
   memset(A,0,sizeof A);
   a[0]=0;
   for(ll i=1;i<=m;i++)
   		cin>>a[i];

   for(ll i=2;i<=n;i++)
   {
   		ll x;
   		cin>>x;
   		//v[i].pb(x);
   		v[x].pb(i);
   }
   dfs(1,0);
   for(ll i=1;i<=n;i++)
   {
   		A[i]+=A[i-1];
   }
   ll cnt=0;
   for(ll i=1;i<=m;i++)
   {
   		if(a[i]<=n)
   		cnt+=(A[n]-A[a[i]-1]);
   }
   cout<<cnt<<endl;
   return 0;
}
