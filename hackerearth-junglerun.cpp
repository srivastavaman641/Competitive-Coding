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
char a[35][35];
int vis[35][35];
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int ans=100000;
int n;
void dfs(int i,int j,int dis)
{
	if(a[i][j]=='E')
	{
		ans=min(dis,ans);
		return;
	}
	vis[i][j]=1;
	for(int k=0;k<4;k++)
	{
		if(vis[i+x[k]][j+y[k]]==0 && i+x[k]>0 && i+x[k]<=n && j+y[k]>0 && j+y[k]<=n && a[i+x[k]][j+y[k]]!='T')
		{
			dfs(i+x[k],j+y[k],dis+1);
		}
	}
	vis[i][j]=0;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
   		for(int j=1;j<=n;j++)
   			cin>>a[i][j];
   }
   for(int i=1;i<=n;i++)
   {
   		for(int j=1;j<=n;j++)
   		{
   			if(a[i][j]=='S')
   			{
   				dfs(i,j,0);
   			}
   		}
   }
   cout<<ans<<endl;
   return 0;
}
