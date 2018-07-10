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
void update(ll x,ll val)
{
	for(;x<=n;x+=x&(-x))
		bit[x]+=val;
}
ll query(ll x)
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
   cin>>n;
   for(ll i=1;i<=n;i++)
   {
   		cin>>a[i];
   }
   ll q;
   cin>>q;
   while(q--)
   {
   		ll x,val;
   		cin>>x>>val;
   		if(x==1)
   		{
   			update(1,-1);
   			update(val+1,1);
   		}
   		else if(x==2)
   		{
   			ll low=1,high=n,flag=0;
   			while(low<=high)
   			{
   				ll mid=(high+low)/2;
   				ll m=a[mid]+query(mid);
   				if(m==val)
   				{
   					flag=1;
   					break;
   				}
   				else if(m>val)
   					high=mid-1;
   				else if(m<val)
   					low=mid+1;
   			}
   			if(flag==1)
   				cout<<"yes"<<endl;
   			else
   				cout<<"no"<<endl;
   		}
   }

   return 0;
}
