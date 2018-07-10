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
ll bit[1000005];
void update(int x,ll val)
{
	if(x==0)return;
	for(;x<=1000004;x+=x&(-x))
		bit[x]+=val;
}
ll query(int x)
{
	ll sum=0;
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
   		ll ans=0;
   		memset(bit,0,sizeof bit);
   		for(int i=1;i<=n;i++)
   		{
   			int x;
   			cin>>x;
   			if(x!=0)
   			ans+=query(x-1);
   			update(x,x);
   		}
   		cout<<ans<<endl;
   }


   return 0;
}
