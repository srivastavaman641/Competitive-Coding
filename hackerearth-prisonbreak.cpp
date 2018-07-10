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
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int a[25][25],vis[25][25];
int n;
int dfs(int i,int j)
{
	int cnt=0;
	if(i==n && j==n){
		return 1;
	}
	vis[i][j]=1;
	for(int k=0;k<4;k++)
	{
		if(i+x[k]>0 && i+x[k]<=n && j+y[k]>0 && j+y[k]<=n && a[i+x[k]][j+y[k]]==0 && vis[i+x[k]][j+y[k]]==0)
		{
			cnt+=dfs(i+x[k],j+y[k]);
		}
	}
	vis[i][j]=0;
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}
		/*if(a[1][1]==1 || a[n][n]==1)
		{
			cout<<0<<endl;
			continue;
		}*/
		
		cout<<dfs(1,1)<<endl;
	}

	return 0;
}
