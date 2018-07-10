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
#define mxn 500004
using namespace std;
ll bit[mxn+5],a[mxn+5],b[mxn+5];
void update(int x,int val)
{
	for(;x<=mxn;x+=x&(-x))
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
   int n,p;
   cin>>n>>p;
   for(int i=0;i<n;i++){
   		cin>>a[i];
   		b[i]=a[i];
   }
   sort(b,b+n);
   for(int i=0;i<n;i++)
   {
   		int idx=lower_bound(b,b+n,a[i])-b;
   		a[i]=idx+1;
   }
   ll l=0,r=0,ans=0,mx=0,mxl;
   for(r=0;r<p;r++)
   {
   		ans+=(query(mxn)-query(a[r]));
   		update(a[r],1);
   		if(ans>mx)
   		{
   			mx=ans;
   			mxl=l;
   		}
   }
   while(r<n)
   {
   		ans-=(query(a[l]-1));
   		update(a[l],-1);
   		l++;
   		ans+=(query(mxn)-query(a[r]));
   		update(a[r],1);
   		if(ans>mx)
   		{
   			mx=ans;
   			mxl=l;
   		}
   		r++;
   }
   cout<<mxl+1<<" "<<mx<<endl;
   return 0;
}
