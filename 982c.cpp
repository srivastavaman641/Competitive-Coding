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
ll ans=0;
vector<int>v[100005];
bool vis[100005];
int dfs(int x)
{
	int cnt=1;
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			cnt+=dfs(v[x][i]);
		}
	}
	if(cnt>0 && cnt%2==0)
		ans++;
	return cnt;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   
   for(int i=0;i<n-1;i++)
   {
   	 int x,y;
   	 cin>>x>>y;
   	 v[x].pb(y);
   	 v[y].pb(x);
   }
   if(n%2==1)
   		{
   			cout<<-1<<endl;
   			return 0;
   		}
   ans=0;
   int c=0;
   int z=dfs(1);
   cout<<ans-1<<endl;
   return 0;
}
