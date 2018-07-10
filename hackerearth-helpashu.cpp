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
ll a[100005],bit[100005];
int n;
void update(int x,int val)
{
	for(;x<=n;x+=(x&(-x)))
		bit[x]+=val;
}
int query(int x)
{
	int sum=0;
	for(;x>0;x-=(x&(-x)))
		sum+=bit[x];
	return sum;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
   		cin>>a[i];
   		a[i]%=2;
   }
   for(int i=1;i<=n;i++)
   {
   		update(i,a[i]);
   }
   int q;
   cin>>q;
   while(q--)
   {
   		int x,l,r;
   		cin>>x>>l>>r;
   		if(x==0)
   		{
   			ll k=query(l)-query(l-1);
   			if((k%2==1 && r%2==0)){
   				update(l,-1);
   			}
   			else if(k%2==0 && r%2==1){
   				update(l,1);
   			}
   		}
   		else if(x==1)
   		{
   			int ans=(r-l+1)-(query(r)-query(l-1));
   			cout<<ans<<endl;
   		}
   		else
   		{
   			ll ans=query(r)-query(l-1);
   			cout<<ans<<endl;
   		}
   }
   return 0;
}
