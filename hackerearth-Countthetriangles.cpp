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
ll a[200005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int i=1,j=1;
	priority_queue<ll>q;
	ll ans=2*n-1,sum=0;
	while(j<=n)
	{
   		// cout<<i<<" "<<j<<endl;
		cout<<sum<<endl;
		if(q.size()<2)
		{
			q.push(a[j]);
			sum+=a[j];
			j++;
			continue;
		}
		if(a[j]<q.top() || sum<a[j])
		{
			ans+=(((j-i)*(j-i+1)/2)-((j-i)+(j-i-1)));
			i++;
			q.pop();
			q.pop();
			sum=0;
			while(i<=j){
				
			}
		}
		else
			j++;
	}
	ans+=(((j-i)*(j-i+1)/2)-((j-i)+(j-i-1)));
	for(int i=1;i<=n-3;i++)
	{
		ll mx=max(a[i],max(a[i+1],a[i+2]));
		ll mn=min(a[i],max(a[i+1],a[i+2]));
		ll mn2=a[i]+a[i+1]+a[i+2]-mx-mn;
		if(mn+mn2>=mx)
			ans++;
	}
	cout<<ans<<endl;


	return 0;
}
