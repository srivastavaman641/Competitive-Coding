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
map<string,int>m;
vector<int>v;
int bit[30005];
void update(int x,int val)
{
	for(;x<=30000;x+=x&(-x))
		bit[x]+=val;
}
int query(int x)
{
	int sum=0;
	for(;x>0;x-=x&(-x))
		sum+=bit[x];
	return sum;
}
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
		string s[n];
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		m.clear();
		v.clear();
		memset(bit,0,sizeof bit);
		for(int i=0;i<n;i++)
		{
			string x;
			cin>>x;
			m[x]=i+1;
		}
		for(int i=0;i<n;i++)
			v.pb(m[s[i]]);
		ll ans=0;
		for(int i=n-1;i>=0;i--)
		{
			ans+=(query(v[i]-1));
			update(v[i],1);
		}
		cout<<ans<<endl;
	}


	return 0;
}
