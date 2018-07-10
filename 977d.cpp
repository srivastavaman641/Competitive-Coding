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
#define INF 1e18
#define pii pair<int,int>

using namespace std;
ll a[105];
int n;
vector<ll>ans;
map<ll,ll>mp;
bool dfs(ll x,int cnt)
{
	if(cnt==n)
		return 1;
	if(x%3==0 && mp[x/3]){
		ans.pb(x/3);
		if(dfs(x/3,cnt+1))
			return 1;
		ans.pop_back();
	}
	if(mp[x*2])
	{
		ans.pb(x*2);
		if(dfs(x*2,cnt+1))
			return 1;
		ans.pop_back();
	}
	return 0;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n;
   for(int i=0;i<n;i++)
   {
   		cin>>a[i];
   		mp[a[i]]++;
   }
   for(int i=0;i<n;i++)
   {
   		ans.clear();
   		ans.pb(a[i]);
   		if(dfs(a[i],1))
   			break;
   }
   for(int i=0;i<ans.size();i++)
   		cout<<ans[i]<<" ";
   return 0;
}
