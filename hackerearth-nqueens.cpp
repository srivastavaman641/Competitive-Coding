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
int vis[15][15];
int n;
bool is_safe(int r,int c)
{
	int i,j;
	for(i=r;i>0;i--)
		if(vis[i][c])
			return false;
	for(i=r,j=c;i>0 && j>0;i--,j--)
		if(vis[i][j])
			return false;
	for(i=r,j=c;i>0 && j<=n;i--,j++)
		if(vis[i][j])
			return false;
	return true;			
}
bool nqueen(int row)
{
	if(row>n)
		return true;
	for(int i=1;i<=n;i++)
	{
		if(is_safe(row,i)){
			vis[row][i]=1;
			if(nqueen(row+1))
				return true;
			vis[row][i]=0;
		}
	}
	return false;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n;
   memset(vis,0,sizeof vis);
   if(nqueen(1)){
   		for(int i=1;i<=n;i++)
   		{
   			for(int j=1;j<=n;j++)
   			{	
   				cout<<vis[i][j]<<" ";
   			}
   		cout<<endl;
   		}
	}
	else
		cout<<"Not possible"<<endl;
   return 0;
}
