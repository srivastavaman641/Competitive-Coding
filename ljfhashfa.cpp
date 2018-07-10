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
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		int a[m+1],b[m+1];
		a[0]=b[0]=0;
		for(int i=1;i<=m;i++)
			cin>>a[i];
		for(int i=1;i<=m;i++)
			cin>>b[i];
		int result=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				ll fib[n+1];
				fib[1]=a[i];
				fib[2]=b[j];
				for(int k=3;k<=n;k++)
					fib[k]=(fib[k-1]+fib[k-2])%mod;
				result=(result+fib[n])%mod;
			}
		}
		cout<<result%mod<<endl;
	}
	return 0;
}
