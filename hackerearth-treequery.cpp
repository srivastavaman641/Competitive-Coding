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
vector<int> v[100005],v1[100005];
ll ans=0,mx=0;
int vis[100005];
void dfs(int x,vector<int>*v){
	vis[x]=1;
	if(v[x].size()==0)
		ans++;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
			dfs(v[x][i],v);
	}
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
   ans=0;
   for(int i=1;i<=n;i++){
   	if(!vis[i])
   	dfs(i,v);
}
   mx=ans;
   ans=0;
   memset(vis,0,sizeof vis);
   for(int i=1;i<=n;i++){
   	if(!vis[i])
   	dfs(i,v1);
}
   mx=max(ans,mx);
   cout<<mx<<endl;

   return 0;
}
