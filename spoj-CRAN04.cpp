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
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int a[n+1];
		a[0]=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0'){
				a[i+1]=0;
				a[i+1]+=a[i];
			}
			else
			{
				a[i+1]=1;
				a[i+1]+=a[i];
			}
		}
		ll cnt=0;
		for(int i=1;i<=n;i++)
		{
			int low=i,high=n,ans=n+1;
			while(low<=high)
			{
				int mid=(low+high)/2;
				if(a[mid]-a[i-1]>=k)
				{
					ans=min(ans,mid);
					high=mid-1;
				}
				else
					low=mid+1;
			}
			if(a[ans]-a[i-1]==k)
			{
				int x=upper_bound(a,a+n+1,a[ans])-a;
				cnt+=(x-ans);
			}
		}
		cout<<cnt<<endl;
	}


	return 0;
}
