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

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin>>n>>m;
   char a[n+1][m+1];
   for(int i=1;i<=n;i++)
   		for(int j=1;j<=m;j++)
   			cin>>a[i][j];
   if(n==1 && m==1)
   {
   		if(a[1][1]=='.' || a[1][1]=='*'){
   			cout<<"YES"<<endl;
   			return 0;
   		}
   		else
   		{
   			cout<<"NO"<<endl;
   			return 0;
   		}
   }
   int x[]={0,0,1,-1,-1,-1,1,1};
   int y[]={1,-1,0,0,1,-1,-1,1};
   for(int i=1;i<=n;i++)
   {
   		for(int j=1;j<=m;j++)
   		{
   			if(a[i][j]=='.')
   			{
   				for(int k=0;k<8;k++)
   				{
   					if(i+x[k]>0 && i+x[k]<=n && j+y[k]>0 && j+y[k]<=m)
   					{
   						if(a[i+x[k]][j+y[k]]=='*')
   						{
   							cout<<"NO"<<endl;
   							return 0;
   						}
   					}
   				}
   			}
   			else if(a[i][j]!='*')
   			{
   				int x11=a[i][j]-'0';
   				int cnt=0;
   				for(int k=0;k<8;k++)
   				{
   					if(i+x[k]>0 && i+x[k]<=n && j+y[k]>0 && j+y[k]<=m)
   					{
   						if(a[i+x[k]][j+y[k]]=='*')
   						{
   							cnt++;
   						}
   					}
   				}
   				if(cnt!=x11)
   				{
   					cout<<"NO"<<endl;
   					return 0;
   				}
   			}
   		}
   }
   cout<<"YES"<<endl;
   return 0;
}
