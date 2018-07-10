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
char a[505][505];
int x[]={1,0,-1,0};
int y[]={0,1,0,-1};
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
   		for(int j=0;j<m;j++)
   		{
   			cin>>a[i][j];
   		}
   }
   for(int i=0;i<n;i++)
   {
   		for(int j=0;j<m;j++)
   		{
   			if(a[i][j]=='S')
   			{
   				for(int k=0;k<4;k++)
   				{
   					if(i+x[k]>=0 && i+x[k]<n && j+y[k]>=0 && j+y[k]<m && a[i+x[k]][j+y[k]]=='W')
   					{
   						cout<<"No"<<endl;
   						return 0;
   					}
   					else if(i+x[k]>=0 && i+x[k]<n && j+y[k]>=0 && j+y[k]<m && a[i+x[k]][j+y[k]]=='.'){
   						a[i+x[k]][j+y[k]]='D';

   					}
   				}
   			}
   		}
   }
   cout<<"Yes"<<endl;
   for(int i=0;i<n;i++)
   {
   		for(int j=0;j<m;j++)
   		{
   			cout<<a[i][j];
   		}
   		cout<<endl;
   }

   return 0;
}
