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
int a[105],b[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,c1=0,c0=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1)
				{
					if(a[i+1]==1)
						b[i]=1;
					else
						b[i]=0;
				}
				else if(i==n)
				{
					if(a[i-1]==1)
						b[i]=1;
					else
						b[i]=0;
				}
				else 
				{
					if(a[i+1]==1 && a[i-1]==1)
						b[i]=1;
					else
						b[i]=0;
				}
			}
			c1=0,c0=0;
			for(int i=1;i<=n;i++)
			{
				a[i]=b[i];
				if(a[i]==1)c1++;
				else c0++;
			}
			if(c1==n || c0==n)
				break;
		}
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
