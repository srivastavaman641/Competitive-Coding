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
#define INF 1e18
#define pii pair<int,int>

using namespace std;
string s="ALLIZZWELL";
int n,m;
int vis[105][105];
int flag=0;
char a[105][105];
int x[]={0,0,1,-1,1,-1,1,-1};
int y[]={1,-1,0,0,1,-1,-1,1};
void dfs(int i,int j,int idx){
	vis[i][j]=1;

	if(idx==9){
		flag=1;
		return;
	}
	for(int k=0;k<8;k++)
	{
		if(i+x[k]>0 && i+x[k]<=n && j+y[k]>0 && j+y[k]<=m && vis[i+x[k]][j+y[k]]==0 && a[i+x[k]][j+y[k]]==s[idx+1])
		{
			dfs(i+x[k],j+y[k],idx+1);
			if(flag==1)
				break;
		}
	}
	vis[i][j]=0;

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
   
   cin>>n>>m;
   memset(vis,0,sizeof vis);
   for(int i=1;i<=n;i++)
   {
   		for(int j=1;j<=m;j++)
   		{
   			cin>>a[i][j];
   		}
   }
   	flag=0;
   for(int i=1;i<=n;i++)
   {
   		for(int j=1;j<=m;j++)
   		{
   			if(a[i][j]=='A'){
   				dfs(i,j,0);
   			}
   		}
   }
   if(flag==1)
   	cout<<"YES"<<endl;
   else 
   	cout<<"NO"<<endl;
  } 
   return 0;
}
