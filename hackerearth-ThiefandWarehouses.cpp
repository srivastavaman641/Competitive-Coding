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
ll a[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		stack<ll>s;
		ll mx=0;
		int i=1;
		while(i<=n){
			if( s.empty() || a[i]>=a[s.top()]){
				s.push(i);
				i++;
			}
			else
			{
				ll x=s.top();
				s.pop();
				ll area=a[x]*((s.empty())?i-1 :i-s.top()-1);
				mx=max(mx,area);
			}
		}
		while(!s.empty())
		{
			ll x=s.top();
			s.pop();
			ll area=a[x]*((s.empty())?i-1 :i-s.top()-1);
			mx=max(mx,area);
		}
		cout<<mx<<endl;
	}


	return 0;
}
