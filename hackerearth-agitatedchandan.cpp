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
vector<pair<int,int> > v[100005],v1[100005];
int di[100005];
ll mx=0,ans=0,pos=0;
int vis[100005];
void dfs(ll x,ll dis){
	vis[x]=1;
   if(dis>mx)
   {
      mx=dis;
      pos=x;
   }
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i].first])
			dfs(v[x][i].first,dis+v[x][i].second);
	}
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
   int n;

   cin>>n;
   for(int i=0;i<100005;i++)
      v[i].clear();
   for(int i=0;i<n-1;i++)
   {
   		int x,y,z;
   		cin>>x>>y>>z;
   		v[x].pb(mp(y,z));
   		v[y].pb(mp(x,z));
   }
   ans=0,mx=0;
   memset(vis,0,sizeof vis);
   dfs(1,0);
   mx=0;
   memset(vis,0,sizeof vis);
   dfs(pos,0);
   if(mx<=100)
      ans=0;
   else if(mx>100 && mx<=1000)
      ans=100;
   else if(mx>1000 && mx<=10000)
      ans=1000;
   else
      ans=10000;
   cout<<ans<<" "<<mx<<endl;
}
   return 0;
}
