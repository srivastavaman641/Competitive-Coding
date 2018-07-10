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
int dp[1000005];
int k,l,m;
int recur(int n)
{
	if(n==0)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	int arr[]={n-l,n-k,n-1};
	for(int i=0;i<3;i++)
		if(arr[i]>=0&&!recur(arr[i]))
			return dp[n]=1;
		return dp[n]=0;
	}
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cin>>k>>l>>m;
		memset(dp,-1,sizeof dp);
		while(m--)
		{
			int n;
			cin>>n;
			int x=recur(n);
			if(x==1)
				cout<<"A";
			else
				cout<<"B";
		}
		cout<<endl;
		return 0;
	}
