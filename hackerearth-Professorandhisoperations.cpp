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
ll a[100005],arr[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>q;
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		arr[x]++;
		arr[y+1]--;
	}
	
	for(int i=1;i<=n;i++)
		arr[i]+=arr[i-1];

	for(int i=1;i<=n;i++)
	{
		if(arr[i]%2)
			swap(a[i],a[n-i+1]);
	}	
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";

	return 0;
}
