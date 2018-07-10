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
int vis[11][11];
int x[]={2,2,-2,-2,1,1,-1,-1};
int y[]={1,-1,1,-1,2,-2,2,-2};
int ans=0;
void dfs(int i,int j,int n){
	if(n==-1)
		return;
	if(n==0 && vis[i][j]==0){
	ans++;
	vis[i][j]=1;
}
	for(int k=0;k<8;k++)
	{
		if(i+x[k]>0 && i+x[k]<=10 && j+y[k]>0 && j+y[k]<=10){
			dfs(i+x[k],j+y[k],n-1);		
		}
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int i,j,n;
   memset(vis,0,sizeof vis);
   cin>>i>>j>>n;
   dfs(i,j,n);
   cout<<ans<<endl;
   return 0;

}