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
ll n,k;
ll a[100005];
vector<ll> v[100005];
ll ans=0;
ll b[10000000];
void dfs(int x,ll y)
{
	y^=a[x];
	ans+=b[y^k];
	b[y]++;
	for(int i=0;i<v[x].size();i++)
	{
		dfs(v[x][i],y);
	}
	b[y]--;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   cin>>n>>k;
   for(int i=1;i<=n;i++)
   {
   		cin>>a[i];
   }
   for(int i=2;i<=n;i++)
   {
   		ll x;
   		cin>>x;
   		v[x].pb(i);
   }
   b[0]=1;
   dfs(1,0);
   cout<<ans<<endl;
   return 0;
}